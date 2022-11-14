#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <jpeglib.h>
#include <stdlib.h>
#include <math.h>

/*
 * 24 Bit Pixel
 * 8bit red
 * 8bit green
 * 8bit blue
 */

/**
 * @brief Contains color data for a single pixel.
 */
struct pixel_rgb_t {

  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

/**
 * @brief Defines an image size.
 */
struct image_size_t {
  unsigned int width;
  unsigned int height;
};

typedef struct pixel_rgb_t pixel_rgb_t;
typedef struct image_size_t image_size_t;

// 𝑃(𝑥, 𝑦) = 𝑃00 ∗ (1 − 𝑑𝑥 ) ∗ (1 − 𝑑𝑦 ) + 𝑃10 ∗ 𝑑𝑥 ∗ (1 − 𝑑𝑦 ) + 𝑃01 ∗ (1 − 𝑑𝑥 ) ∗ 𝑑𝑦 + 𝑃11 ∗ 𝑑𝑥∗ 𝑑𝑧
uint8_t interpolate(uint8_t *p00, uint8_t *p01, uint8_t *p10, uint8_t *p11, uint8_t *dx, uint8_t *dy) {

  return (*p00 * (1 - *dx) * (1 - *dy) + *p10 * *dx * (1 - *dy) + *p01 * (1 - *dx) * *dy + *p11 * *dx * *dy); //letze maybe dz 

}

/**
 * @brief Scales an image by applying a billinear interpolation filter.
 *
 * @param in pixel data of input image
 * @param out  pixel data of output image. Has to be pre allocated.
 * @param src_sz the size of the input image
 * @param trgt_sz the desired output size.
 */
void resize_image(pixel_rgb_t *in, pixel_rgb_t *out, image_size_t src_sz,
                  image_size_t trgt_sz) {
  
  uint8_t dx = trgt_sz.width / src_sz.width;
  uint8_t dy = trgt_sz.height / src_sz.height;

  double x_index_unrounded = 0.0;
  double y_index_unrounded = 0.0;

  for(int i=0; i<trgt_sz.height; i++) { //puts into next row
    y_index_unrounded += dy;
    for(int j=0; i<trgt_sz.width; j++) { //puts into next collumn
      x_index_unrounded += dx;
      // ROUND dx and dy to get pixel 
      int x_index_rounded = round(x_index_unrounded);
      int y_index_rounded = round(y_index_unrounded);

      // calculating indexes
      int p11_index = x_index_rounded + (y_index_rounded * src_sz.width); 
      int p00_index = p11_index - 1 - src_sz.width;
      int p01_index = p11_index - src_sz.width;
      int p10_index = p11_index - 1;

      //EDGE CASES
      //EDGE CASE bottom right of image
      if(p11_index > (src_sz.width + src_sz.height)) {
        p11_index = src_sz.width + src_sz.height;
        p00_index = p11_index - 1 - src_sz.width;
        p01_index = p11_index - src_sz.width;
        p10_index = p11_index - 1;
      }

      // EDGE CASE top left of image
      if(p00_index <= 0) {
        p00_index = 0;
        p01_index = 1;
        p10_index = src_sz.width;
        p11_index = 1 + src_sz.width;
      }

      pixel_rgb_t p11 = in[p11_index];
      pixel_rgb_t p00 = in[p11_index - 1 - src_sz.width];
      pixel_rgb_t p01 = in[p11_index - src_sz.width];
      pixel_rgb_t p10 = in[p11_index - 1];

      uint8_t new_pixel_red = interpolate(&p00.red, &p01.red, &p10.red, &p11.red, &dx, &dy);
      uint8_t new_pixel_green = interpolate(&p00.green, &p01.green, &p10.green, &p11.green, &dx, &dy);
      uint8_t new_pixel_blue = interpolate(&p00.blue, &p01.blue, &p10.blue, &p11.blue, &dx, &dy);

      pixel_rgb_t new_pixel = {new_pixel_red, new_pixel_green, new_pixel_blue};

      out[j + (i * trgt_sz.width)] = new_pixel;
    }
  }

}

int round_to_index(double f) {
  return (int) (f - fmod(f, 1.0));
}


/**
 * @brief Loads pixels from a JPEG file into memory.
 * @param name the path of the file to read
 * @param img pointer to pixel data. Will be allocated.
 * @param size the size of the image. Will be set by this function
 */
void load_jpeg(const char *name, pixel_rgb_t **img, image_size_t *const size) {
  uint8_t r, g, b;
  int width, height;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;

  FILE *infile;
  JSAMPARRAY pJpegBuffer;
  int row_stride;
  if ((infile = fopen(name, "rb")) == NULL) {
    fprintf(stderr, "can't open %s\n", name);
    exit(1);
  }
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo, infile);
  (void)jpeg_read_header(&cinfo, TRUE);
  (void)jpeg_start_decompress(&cinfo);
  width = cinfo.output_width;
  height = cinfo.output_height;

  *img = calloc((size_t)width * height, sizeof(pixel_rgb_t));
  pixel_rgb_t *current_pixel = *img;
  if (!*img) {
    printf("NO MEM FOR JPEG CONVERT!\n");
    exit(1);
  }

  row_stride = width * cinfo.output_components;
  pJpegBuffer = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo, JPOOL_IMAGE,
                                           row_stride, 1);

  while (cinfo.output_scanline < cinfo.output_height) {
    (void)jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
    for (int x = 0; x < width; x++) {
      r = pJpegBuffer[0][cinfo.output_components * x];
      if (cinfo.output_components > 2) {
        g = pJpegBuffer[0][cinfo.output_components * x + 1];
        b = pJpegBuffer[0][cinfo.output_components * x + 2];
      } else {
        g = r;
        b = r;
      }

      // r, g and b contain the color information for the channels read, green
      // and blue
      //  current_pixel is your current pixel to fill with info from the jpeg.

      // Putting the r,g,b values into the struct
      // TODO more documentation i guess?
      current_pixel->red = r;
      current_pixel->green = g;
      current_pixel->blue = b;

      current_pixel++;
    }
  }
  fclose(infile);
  (void)jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  size->height = (uint32_t)height;
  size->width = (uint32_t)width;
}

/**
 * @brief Writes pixel data to a JPEG file with 80% quality and defined image
 * size.
 * @param pixel_data the pixel to compress
 * @param size the size of this image
 * @param filename paht to write this file to.
 */
void save_jpeg(const pixel_rgb_t *pixel_data, const image_size_t size,
               const char *filename) {
  FILE *outfile = fopen(filename, "wb");

  if (!outfile) {
    fprintf(stderr, "can't open %s\n for write", filename);
    exit(1);
  }

  struct jpeg_compress_struct jpeg_info;
  struct jpeg_error_mgr jpeg_error;

  jpeg_info.err = jpeg_std_error(&jpeg_error);
  jpeg_create_compress(&jpeg_info);
  jpeg_stdio_dest(&jpeg_info, outfile);

  jpeg_info.image_width = size.width;
  jpeg_info.image_height = size.height;
  jpeg_info.input_components = 3;
  jpeg_info.in_color_space = JCS_RGB;

  jpeg_set_defaults(&jpeg_info);
  jpeg_set_quality(&jpeg_info, 80, true);
  jpeg_start_compress(&jpeg_info, true);

  JSAMPROW row_pointer;

  pixel_rgb_t p;

  unsigned char *row =
      malloc(sizeof(unsigned char) * 3 *
             size.width); // this points to beginning of current row

  // goes creates image row by row until height is reached
  while (jpeg_info.next_scanline < jpeg_info.image_height) {

    // current is your current scanline to fill with information.
    unsigned char *current = row; // red,green,blue,red,green,blue

    // this is the index of the beginning of the current row in your source
    // array.
    unsigned int current_row = jpeg_info.next_scanline * size.width;

    for (int i = 0; i < (size.width); i++) {
      *current = pixel_data[current_row + i].red;
      current++;
      *current = pixel_data[current_row + i].green;
      current++;
      *current = pixel_data[current_row + i].blue;
      current++;
    }

    row_pointer = (JSAMPROW)row;
    jpeg_write_scanlines(&jpeg_info, &row_pointer, true);
  }

  free(row);

  jpeg_finish_compress(&jpeg_info); // this is causing the overflow
}

int main(int argc, char **argv) {
  int option_index = 0;
  char *input_file_path = NULL;
  char *output_file_path = NULL;
  image_size_t resize_size;
  resize_size.height = 0;
  resize_size.width = 0;

  while ((option_index = getopt(argc, argv, "i:o:w:h:")) != -1) {
    switch (option_index) {
    case 'i':
      input_file_path = optarg;
      break;
    case 'o':
      output_file_path = optarg;
      break;
    case 'h':
      resize_size.height = atoi(optarg); //atoi converts string to int
      break;
    case 'w':
      resize_size.width = atoi(optarg);
      break;
    default:
      printf("incorrect options\n");
      return 1;
    } // end block for switch
  }   // end block for while

  // TODO this is not pretty with zeros
  if (input_file_path == NULL || output_file_path == NULL || resize_size.height == 0 || resize_size.width == 0) {
    printf("Missing inputs");
    return 1;
  }

  // image data
  pixel_rgb_t *img;
  image_size_t size;
  pixel_rgb_t *scaled_img = calloc((size_t)resize_size.width * resize_size.height, sizeof(pixel_rgb_t));

  printf("%d", resize_size.width);

  load_jpeg(input_file_path, &img, &size);

  resize_image(img, scaled_img, size, resize_size);

  save_jpeg(scaled_img, resize_size, output_file_path);

  return 0;
}
