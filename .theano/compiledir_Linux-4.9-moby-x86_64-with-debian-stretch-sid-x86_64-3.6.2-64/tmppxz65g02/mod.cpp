#include <Python.h>
#include <iostream>
#include "theano_mod_helper.h"
#include <math.h>
#include <numpy/arrayobject.h>
#include <numpy/arrayscalars.h>
#include <stdio.h>
//////////////////////
////  Support Code
//////////////////////

    extern "C"
    {

        void xerbla_(char*, void *);

    /***********/
    /* Level 1 */
    /***********/

    /* Single Precision */

        void srot_(const int*, float *, const int*, float *, const int*, const float *, const float *);
        void srotg_(float *,float *,float *,float *);
        void srotm_( const int*, float *, const int*, float *, const int*, const float *);
        void srotmg_(float *,float *,float *,const float *, float *);
        void sswap_( const int*, float *, const int*, float *, const int*);
        void scopy_( const int*, const float *, const int*, float *, const int*);
        void saxpy_( const int*, const float *, const float *, const int*, float *, const int*);
        float sdot_(const int*, const float *, const int*, const float *, const int*);
        void sdot_sub_(const int*, const float *, const int*, const float *, const int*, float *);
        void sdsdot_sub_( const int*, const float *, const float *, const int*, const float *, const int*, float *);
        void sscal_( const int*, const float *, float *, const int*);
        void snrm2_sub_( const int*, const float *, const int*, float *);
        void sasum_sub_( const int*, const float *, const int*, float *);
        void isamax_sub_( const int*, const float * , const int*, const int*);

    /* Double Precision */

        void drot_(const int*, double *, const int*, double *, const int*, const double *, const double *);
        void drotg_(double *,double *,double *,double *);
        void drotm_( const int*, double *, const int*, double *, const int*, const double *);
        void drotmg_(double *,double *,double *,const double *, double *);
        void dswap_( const int*, double *, const int*, double *, const int*);
        void dcopy_( const int*, const double *, const int*, double *, const int*);
        void daxpy_( const int*, const double *, const double *, const int*, double *, const int*);
        void dswap_( const int*, double *, const int*, double *, const int*);
        double ddot_(const int*, const double *, const int*, const double *, const int*);
        void dsdot_sub_(const int*, const float *, const int*, const float *, const int*, double *);
        void ddot_sub_( const int*, const double *, const int*, const double *, const int*, double *);
        void dscal_( const int*, const double *, double *, const int*);
        void dnrm2_sub_( const int*, const double *, const int*, double *);
        void dasum_sub_( const int*, const double *, const int*, double *);
        void idamax_sub_( const int*, const double * , const int*, const int*);

    /* Single Complex Precision */

        void cswap_( const int*, void *, const int*, void *, const int*);
        void ccopy_( const int*, const void *, const int*, void *, const int*);
        void caxpy_( const int*, const void *, const void *, const int*, void *, const int*);
        void cswap_( const int*, void *, const int*, void *, const int*);
        void cdotc_sub_( const int*, const void *, const int*, const void *, const int*, void *);
        void cdotu_sub_( const int*, const void *, const int*, const void *, const int*, void *);
        void cscal_( const int*, const void *, void *, const int*);
        void icamax_sub_( const int*, const void *, const int*, const int*);
        void csscal_( const int*, const float *, void *, const int*);
        void scnrm2_sub_( const int*, const void *, const int*, float *);
        void scasum_sub_( const int*, const void *, const int*, float *);

    /* Double Complex Precision */

        void zswap_( const int*, void *, const int*, void *, const int*);
        void zcopy_( const int*, const void *, const int*, void *, const int*);
        void zaxpy_( const int*, const void *, const void *, const int*, void *, const int*);
        void zswap_( const int*, void *, const int*, void *, const int*);
        void zdotc_sub_( const int*, const void *, const int*, const void *, const int*, void *);
        void zdotu_sub_( const int*, const void *, const int*, const void *, const int*, void *);
        void zdscal_( const int*, const double *, void *, const int*);
        void zscal_( const int*, const void *, void *, const int*);
        void dznrm2_sub_( const int*, const void *, const int*, double *);
        void dzasum_sub_( const int*, const void *, const int*, double *);
        void izamax_sub_( const int*, const void *, const int*, const int*);

    /***********/
    /* Level 2 */
    /***********/

    /* Single Precision */

        void sgemv_(char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void sgbmv_(char*, const int*, const int*, const int*, const int*, const float *,  const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void ssymv_(char*, const int*, const float *, const float *, const int*, const float *,  const int*, const float *, float *, const int*);
        void ssbmv_(char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void sspmv_(char*, const int*, const float *, const float *, const float *, const int*, const float *, float *, const int*);
        void strmv_( char*, char*, char*, const int*, const float *, const int*, float *, const int*);
        void stbmv_( char*, char*, char*, const int*, const int*, const float *, const int*, float *, const int*);
        void strsv_( char*, char*, char*, const int*, const float *, const int*, float *, const int*);
        void stbsv_( char*, char*, char*, const int*, const int*, const float *, const int*, float *, const int*);
        void stpmv_( char*, char*, char*, const int*, const float *, float *, const int*);
        void stpsv_( char*, char*, char*, const int*, const float *, float *, const int*);
        void sger_( const int*, const int*, const float *, const float *, const int*, const float *, const int*, float *, const int*);
        void ssyr_(char*, const int*, const float *, const float *, const int*, float *, const int*);
        void sspr_(char*, const int*, const float *, const float *, const int*, float *);
        void sspr2_(char*, const int*, const float *, const float *, const int*, const float *, const int*,  float *);
        void ssyr2_(char*, const int*, const float *, const float *, const int*, const float *, const int*,  float *, const int*);

    /* Double Precision */

        void dgemv_(char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dgbmv_(char*, const int*, const int*, const int*, const int*, const double *,  const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dsymv_(char*, const int*, const double *, const double *, const int*, const double *,  const int*, const double *, double *, const int*);
        void dsbmv_(char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dspmv_(char*, const int*, const double *, const double *, const double *, const int*, const double *, double *, const int*);
        void dtrmv_( char*, char*, char*, const int*, const double *, const int*, double *, const int*);
        void dtbmv_( char*, char*, char*, const int*, const int*, const double *, const int*, double *, const int*);
        void dtrsv_( char*, char*, char*, const int*, const double *, const int*, double *, const int*);
        void dtbsv_( char*, char*, char*, const int*, const int*, const double *, const int*, double *, const int*);
        void dtpmv_( char*, char*, char*, const int*, const double *, double *, const int*);
        void dtpsv_( char*, char*, char*, const int*, const double *, double *, const int*);
        void dger_( const int*, const int*, const double *, const double *, const int*, const double *, const int*, double *, const int*);
        void dsyr_(char*, const int*, const double *, const double *, const int*, double *, const int*);
        void dspr_(char*, const int*, const double *, const double *, const int*, double *);
        void dspr2_(char*, const int*, const double *, const double *, const int*, const double *, const int*,  double *);
        void dsyr2_(char*, const int*, const double *, const double *, const int*, const double *, const int*,  double *, const int*);

    /* Single Complex Precision */

        void cgemv_(char*, const int*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void cgbmv_(char*, const int*, const int*, const int*, const int*, const void *,  const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void chemv_(char*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void chbmv_(char*, const int*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void chpmv_(char*, const int*, const void *, const void *, const void *, const int*, const void *, void *, const int*);
        void ctrmv_( char*, char*, char*, const int*, const void *, const int*, void *, const int*);
        void ctbmv_( char*, char*, char*, const int*, const int*, const void *, const int*, void *, const int*);
        void ctpmv_( char*, char*, char*, const int*, const void *, void *, const int*);
        void ctrsv_( char*, char*, char*, const int*, const void *, const int*, void *, const int*);
        void ctbsv_( char*, char*, char*, const int*, const int*, const void *, const int*, void *, const int*);
        void ctpsv_( char*, char*, char*, const int*, const void *, void *,const int*);
        void cgerc_( const int*, const int*, const void *, const void *, const int*, const void *, const int*, void *, const int*);
        void cgeru_( const int*, const int*, const void *, const void *, const int*, const void *, const int*, void *,  const int*);
        void cher_(char*, const int*, const float *, const void *, const int*, void *, const int*);
        void cher2_(char*, const int*, const void *, const void *, const int*, const void *, const int*, void *, const int*);
        void chpr_(char*, const int*, const float *, const void *, const int*, void *);
        void chpr2_(char*, const int*, const float *, const void *, const int*, const void *, const int*, void *);

    /* Double Complex Precision */

        void zgemv_(char*, const int*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void zgbmv_(char*, const int*, const int*, const int*, const int*, const void *,  const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void zhemv_(char*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void zhbmv_(char*, const int*, const int*, const void *, const void *, const int*, const void *, const int*, const void *, void *, const int*);
        void zhpmv_(char*, const int*, const void *, const void *, const void *, const int*, const void *, void *, const int*);
        void ztrmv_( char*, char*, char*, const int*, const void *, const int*, void *, const int*);
        void ztbmv_( char*, char*, char*, const int*, const int*, const void *, const int*, void *, const int*);
        void ztpmv_( char*, char*, char*, const int*, const void *, void *, const int*);
        void ztrsv_( char*, char*, char*, const int*, const void *, const int*, void *, const int*);
        void ztbsv_( char*, char*, char*, const int*, const int*, const void *, const int*, void *, const int*);
        void ztpsv_( char*, char*, char*, const int*, const void *, void *,const int*);
        void zgerc_( const int*, const int*, const void *, const void *, const int*, const void *, const int*, void *, const int*);
        void zgeru_( const int*, const int*, const void *, const void *, const int*, const void *, const int*, void *,  const int*);
        void zher_(char*, const int*, const double *, const void *, const int*, void *, const int*);
        void zher2_(char*, const int*, const void *, const void *, const int*, const void *, const int*, void *, const int*);
        void zhpr_(char*, const int*, const double *, const void *, const int*, void *);
        void zhpr2_(char*, const int*, const double *, const void *, const int*, const void *, const int*, void *);

    /***********/
    /* Level 3 */
    /***********/

    /* Single Precision */

        void sgemm_(char*, char*, const int*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void ssymm_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void ssyrk_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, float *, const int*);
        void ssyr2k_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void strmm_(char*, char*, char*, char*, const int*, const int*, const float *, const float *, const int*, float *, const int*);
        void strsm_(char*, char*, char*, char*, const int*, const int*, const float *, const float *, const int*, float *, const int*);

    /* Double Precision */

        void dgemm_(char*, char*, const int*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dsymm_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dsyrk_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, double *, const int*);
        void dsyr2k_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void dtrmm_(char*, char*, char*, char*, const int*, const int*, const double *, const double *, const int*, double *, const int*);
        void dtrsm_(char*, char*, char*, char*, const int*, const int*, const double *, const double *, const int*, double *, const int*);

    /* Single Complex Precision */

        void cgemm_(char*, char*, const int*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void csymm_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void chemm_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void csyrk_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, float *, const int*);
        void cherk_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, float *, const int*);
        void csyr2k_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void cher2k_(char*, char*, const int*, const int*, const float *, const float *, const int*, const float *, const int*, const float *, float *, const int*);
        void ctrmm_(char*, char*, char*, char*, const int*, const int*, const float *, const float *, const int*, float *, const int*);
        void ctrsm_(char*, char*, char*, char*, const int*, const int*, const float *, const float *, const int*, float *, const int*);

    /* Double Complex Precision */

        void zgemm_(char*, char*, const int*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void zsymm_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void zhemm_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void zsyrk_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, double *, const int*);
        void zherk_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, double *, const int*);
        void zsyr2k_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void zher2k_(char*, char*, const int*, const int*, const double *, const double *, const int*, const double *, const int*, const double *, double *, const int*);
        void ztrmm_(char*, char*, char*, char*, const int*, const int*, const double *, const double *, const int*, double *, const int*);
        void ztrsm_(char*, char*, char*, char*, const int*, const int*, const double *, const double *, const int*, double *, const int*);

    }
    
    extern "C"
    {
        void openblas_set_num_threads(int);
        void goto_set_num_threads(int);
        int openblas_get_num_threads(void);
    }
    
// This uses a lot of code from Caffe (http://caffe.berkeleyvision.org/);
// sources are clearly marked. Below we reproduce the original license of
// the Caffe software.
/*
Copyright (c) 2014, The Regents of the University of California (Regents)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// (borrowed from Caffe: https://github.com/BVLC/caffe/blob/master/src/caffe/util/im2col.cpp)
// Loops for fast unfold + copy
void im2col(const npy_float* data_im, const int channels,
    const int height, const int width, const int kernel_h, const int kernel_w,
    const int dilation_h, const int dilation_w,
    const int pad_h, const int pad_w,
    const int stride_h, const int stride_w,
    npy_float* data_col) {
  // Implicit dilated kernel size
  int dil_kernel_h = (kernel_h - 1) * dilation_h + 1;
  int dil_kernel_w = (kernel_w - 1) * dilation_w + 1;
  int height_col = (height + 2 * pad_h - dil_kernel_h) / stride_h + 1;
  int width_col = (width + 2 * pad_w - dil_kernel_w) / stride_w + 1;
  int channels_col = channels * kernel_h * kernel_w;
  for (int c = 0; c < channels_col; ++c) {
    int w_offset = c % kernel_w;
    int h_offset = (c / kernel_w) % kernel_h;
    int c_im = c / kernel_h / kernel_w;
    for (int h = 0; h < height_col; ++h) {
      int h_pad = h * stride_h - pad_h + h_offset * dilation_h;
      for (int w = 0; w < width_col; ++w) {
        int w_pad = w * stride_w - pad_w + w_offset * dilation_w;
        if (h_pad >= 0 && h_pad < height && w_pad >= 0 && w_pad < width)
          data_col[(npy_intp)(c * height_col + h) * width_col + w] =
            data_im[(npy_intp)(c_im * height + h_pad) * width + w_pad];
        else
          data_col[(npy_intp)(c * height_col + h) * width_col + w] = 0.;
      }
    }
  }
}

// Unlike the Caffe and Theano GPU verions, the data_im array is set to zero
// before the col2im call rather than doing it here. So, the result is just
// accumulated into data_im.
void col2im(const npy_float* data_col, const int channels,
    const int height, const int width, const int patch_h, const int patch_w,
    const int dilation_h, const int dilation_w,
    const int pad_h, const int pad_w, const int stride_h,
    const int stride_w, npy_float* data_im) {
  // Implicit dilated patch
  int dil_patch_h = (patch_h - 1) * dilation_h + 1;
  int dil_patch_w = (patch_w - 1) * dilation_w + 1;
  int height_col = (height + 2 * pad_h - dil_patch_h) / stride_h + 1;
  int width_col = (width + 2 * pad_w - dil_patch_w) / stride_w + 1;
  int num_kernels = channels * height * width;
  int channels_col = channels * patch_h * patch_w;
  for (int c = 0; c < channels_col; ++c) {
    int w_offset = c % patch_w;
    int h_offset = (c / patch_w) % patch_h;
    int c_im = c / patch_h / patch_w;
    for (int h = 0; h < height_col; ++h) {
      int h_pad = h * stride_h - pad_h + h_offset * dilation_h;
      for (int w = 0; w < width_col; ++w) {
        int w_pad = w * stride_w - pad_w + w_offset * dilation_w;
        if (h_pad >= 0 && h_pad < height && w_pad >= 0 && w_pad < width)
          data_im[(npy_intp)(c_im * height + h_pad) * width + w_pad] +=
            data_col[(npy_intp)(c * height_col + h) * width_col + w];

      }
    }
  }
}


// Theano op code
// GPU version authors: Arjun Jain, Frederic Bastien, Jan Schlueter
// Reference code: https://github.com/BVLC/caffe/blob/master/src/caffe/layers/conv_layer.cu
//   and https://github.com/torch/cunn/blob/master/SpatialConvolutionMM.cu
// CPU version author: Jesse Livezey
// CPU version adapted from GPU version
PyArrayObject* corrMM(PyArrayObject* bottom,
                      PyArrayObject* weight,
                      PyArrayObject* top,
                      const int direction,
                      const int dH = 1,
                      const int dW = 1,
                      const int dilH = 1,
                      const int dilW = 1,
                      const int padH = 0,
                      const int padW = 0)
{
    if (PyArray_NDIM(bottom) != 4)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM requires bottom of 4D");
        return NULL;
    }
    if (PyArray_TYPE(bottom) != NPY_FLOAT)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM received bottom with wrong type.");
        return NULL;
    }

    if (PyArray_NDIM(weight) != 4)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM requires weight of 4D");
        return NULL;
    }
    if (PyArray_TYPE(weight) != NPY_FLOAT)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM received weight with wrong type.");
        return NULL;
    }

    if (PyArray_NDIM(top) != 4)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM requires top of 4D");
        return NULL;
    }
    if (PyArray_TYPE(top) != NPY_FLOAT)
    {
        PyErr_SetString(PyExc_ValueError, "CorrMM received top with wrong type.");
        return NULL;
    }
    // Ensure data is contiguous
    bottom = PyArray_GETCONTIGUOUS(bottom);
    weight = PyArray_GETCONTIGUOUS(weight);
    top = PyArray_GETCONTIGUOUS(top);

    // Extract some shape information for later and check shape consistency
    // bottom: (batchSize, nChannels, bottomHeight, bottomWidth)
    const int batchSize = PyArray_DIMS(bottom)[0];
    const int nChannels = PyArray_DIMS(bottom)[1];
    const int bottomHeight = PyArray_DIMS(bottom)[2];
    const int bottomWidth = PyArray_DIMS(bottom)[3];
    // weights: (nFilters, nChannels, rows, columns)
    const int nFilters = PyArray_DIMS(weight)[0];
    const int kH = PyArray_DIMS(weight)[2];
    const int kW = PyArray_DIMS(weight)[3];
    if (nChannels != PyArray_DIMS(weight)[1]) {
        PyErr_SetString(PyExc_ValueError,
                "CorrMM images and kernel must have the same stack size\n");
        return NULL;
    }
    // implicit dilated filter
    const int dil_kH = (kH - 1) * dilH + 1;
    const int dil_kW = (kW - 1) * dilW + 1;
    // top: (batchSize, nFilters, topHeight, topWidth)
    const int topHeightNoDH = (bottomHeight + 2*padH - dil_kH);
    const int topWidthNoDW  = (bottomWidth + 2*padW - dil_kW);
    // the above values might be negative so we need to use Python-like
    // flooring integer division to be compatible with get_conv_output.
    // note: this macro implements Python's // for negative x only
#define _CONV_FLOORDIV_X(x,y) ((x < 0) ? (- ((-x) / y) - (((-x) % y) == 0 ? 0 : 1)) : (x / y))
    const int topHeight = _CONV_FLOORDIV_X(topHeightNoDH, dH) + 1;
    const int topWidth  = _CONV_FLOORDIV_X(topWidthNoDW, dW) + 1;
#undef _CONV_FLOORDIV
    if (batchSize != PyArray_DIMS(top)[0] ||
            nFilters != PyArray_DIMS(top)[1] ||
            topHeight != PyArray_DIMS(top)[2] ||
            topWidth != PyArray_DIMS(top)[3]) {
        PyErr_Format(PyExc_ValueError,
                "CorrMM shape inconsistency:\n"
                "  bottom shape: %d %d %d %d\n"
                "  weight shape: %d %d %d %d\n"
                "  top shape: %ld %ld %ld %ld (expected %d %d %d %d)\n",
                batchSize, nChannels, bottomHeight, bottomWidth,
                nFilters, nChannels, kH, kW,
                PyArray_DIMS(top)[0], PyArray_DIMS(top)[1],
                PyArray_DIMS(top)[2], PyArray_DIMS(top)[3],
                batchSize, nFilters, topHeight, topWidth);
        return NULL;
    }

    // Create temporary columns
    int max_threads = 1;
    if (batchSize < max_threads) {
        max_threads = batchSize;
    }
    npy_intp col_dim[3];
    col_dim[0] = (npy_intp)max_threads;
    col_dim[1] = (npy_intp)(nChannels * kW * kH);
    col_dim[2] = (npy_intp)(topHeight * topWidth);

    //Change to PyArray_ZEROS which is faster than PyArray_EMPTY.
    PyArrayObject* col = (PyArrayObject*)PyArray_ZEROS(3,
            col_dim,
            PyArray_TYPE(top),
            0); 
    if (NULL == col) {
        PyErr_Format(PyExc_RuntimeError,
                "CorrMM failed to allocate working memory of"
                " %ld x %ld x %ld\n",
                col_dim[0], col_dim[1], col_dim[2]);
        return NULL;
    }

    // Define some useful variables
    const int bottom_stride = PyArray_STRIDES(bottom)[0]/4.000000;
    const int top_stride = PyArray_STRIDES(top)[0]/4.000000;
    const int K_ = col_dim[1];
    const int N_ = col_dim[2];
    const int col_stride = (K_ * N_);
    const int M_ = nFilters;
    const float one = 1.0;
    const float zero = 0.0;
    char NTrans = 'N';
    char Trans = 'T';
    PyArrayObject *output;

    if (batchSize == 0 || nChannels == 0 || nFilters == 0) {
        switch(direction) {
        case 0:
            output = top;
            break;
        case 1:
            output = weight;
            break;
        case 2:
            output = bottom;
            break;
        default:
            return NULL;
        }
        PyArray_FILLWBYTE(output, 0);
    }
    else if (direction == 0) {  // forward pass
        output = top;
        // valid correlation: im2col, then gemm
        // Iterate over batch
        int blas_threads_saved = 0;
        // Always forcing gemm to one thread when OpenMP is enalbed for best and stable performance.
        (1);
        
        for (int n = 0; n < batchSize; ++n) {
            int tid = 0;
            // First, im2col
            im2col((npy_float*)PyArray_DATA(bottom) + n * bottom_stride, nChannels, bottomHeight,
                   bottomWidth, kH, kW, dilH, dilW, padH, padW, dH, dW,
                   (npy_float*)PyArray_DATA(col)+ tid * col_stride);
            // Second, gemm
            sgemm_(&NTrans, &NTrans,
                   &N_, &M_, &K_,
                   &one,
                   (npy_float*)PyArray_DATA(col)+ tid * col_stride, &N_,
                   (npy_float*)PyArray_DATA(weight), &K_,
                   &zero,
                   (npy_float*)PyArray_DATA(top) + n * top_stride, &N_);
        }
        // Restore to previous blas threads
        (blas_threads_saved);

        /*
        // Original caffe code for comparison
        // Note that this code was translated from the Theano GPU code,
        // not the Caffe CPU code.
        // https://github.com/BVLC/caffe/blob/master/src/caffe/layers/conv_layer.cu
        // Note that this is for grouped convolution; we can ignore groups here,
        // but the group-related offsets help explain what M_, N_ and K_ are
        int weight_offset = M_ * K_;
        int col_offset = K_ * N_;
        int top_offset = M_ * N_;
        for (int n = 0; n < num_; ++n) {
          // First, im2col
          im2col_gpu(bottom_data + bottom[i]->offset(n), channels_, height_,
              width_, kernel_h_, kernel_w_, pad_h_, pad_w_, stride_h_, stride_w_,
              col_data);
          // Second, innerproduct with groups
          for (int g = 0; g < group_; ++g) {
            caffe_gpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, M_, N_, K_,
              (Dtype)1., weight + weight_offset * g, col_data + col_offset * g,
              (Dtype)0., top_data + (*top)[i]->offset(n) + top_offset * g);
            == (see https://github.com/BVLC/caffe/blob/master/src/caffe/util/math_functions.cu#L16)
            cublasSgemm(CUBLAS_OP_N, CUBLAS_OP_N,
              N_, M_, K_,
              1.,
              col_data + col_offset * g, N_,
              weight + weight_offset * g, K_,
              0.,
              top_data + (*top)[i]->offset(n) + top_offset * g, N_);
          }
        }
        */
    }
    else if (direction == 1) {  // backprop wrt. weights
        output = weight;
        npy_intp weight_dim[2];
        weight_dim[0] = (npy_intp)max_threads;
        weight_dim[1] = (npy_intp)(M_ * K_);
        PyArrayObject* local_weight = (PyArrayObject*)PyArray_ZEROS(2,
                                   weight_dim, PyArray_TYPE(weight), 0);

        if (NULL == local_weight)
        {
            PyErr_Format(PyExc_RuntimeError,
                    "CorrMM failed to allocate weight memory of %ld x %ld\n",
                    weight_dim[0], weight_dim[1]);
            return NULL;
        }
        
        // valid convolution: im2col, then gemm
        // Iterate over batch
        int blas_threads_saved = 0;
        // Always forcing gemm to one thread when OpenMP is enalbed for best and stable performance.
        (1);
        // OMP for batch-level paralization
        
        for (int n = 0; n < batchSize; ++n) {
            int tid = 0;
            // First, im2col
            im2col((npy_float*)PyArray_DATA(bottom) + n * bottom_stride, nChannels, bottomHeight,
                   bottomWidth, kH, kW, dilH, dilW, padH, padW, dH, dW,
                   (npy_float*)PyArray_DATA(col)+ tid * col_stride);
            // Second, gemm
            // Note that we accumulate into weight. We do so by setting beta = 0
            // for the first iteration and beta = 1 for subsequent ones. (This
            // is faster than setting weight to all zeros before the loop.)
            sgemm_(&Trans, &NTrans,
                   &K_, &M_, &N_,
                   &one,
                   (npy_float*)PyArray_DATA(col) + tid * col_stride, &N_,
                   (npy_float*)PyArray_DATA(top) + n * top_stride, &N_,
                   (n == 0) ? &zero : &one,
                   (npy_float*)PyArray_DATA(local_weight) + 
                   tid * weight_dim[1], &K_);
        }
        // Restore to previous blas threads
        (blas_threads_saved);

        //aggregate weights
        memset((npy_float*)PyArray_DATA(weight), 0, M_ * K_*sizeof(npy_float));
        /*
         * Put index "j" into outer loop to get the
         * correct result when openmp is used.
         */
        
        for(int j = 0; j < weight_dim[1]; ++j){
            for(int i = 0; i < max_threads; ++i){
                ((npy_float*)PyArray_DATA(weight))[j] += 
                    *((npy_float*)PyArray_DATA(local_weight) +
                    i * weight_dim[1] + j);
            }
        }
        Py_DECREF(local_weight);
        /*
        // Original caffe code for comparison
        // Note that this code was translated from the Theano GPU code,
        // not the Caffe CPU code.
        // https://github.com/BVLC/caffe/blob/master/src/caffe/layers/conv_layer.cu
        // Note that this is for grouped convolution; we can ignore groups
        for (int n = 0; n < num_; ++n) {
          // Since we saved memory in the forward pass by not storing all col
          // data, we will need to recompute them.
          im2col_gpu(bottom_data + (*bottom)[i]->offset(n), channels_, height_,
                     width_, kernel_h_, kernel_w_, pad_h_, pad_w_,
                     stride_h_, stride_w_, col_data);
          // gradient w.r.t. weight. Note that we will accumulate diffs.
          for (int g = 0; g < group_; ++g) {
            caffe_gpu_gemm<Dtype>(CblasNoTrans, CblasTrans, M_, K_, N_,
                (Dtype)1., top_diff + top[i]->offset(n) + top_offset * g,
                col_data + col_offset * g, (Dtype)1.,
                weight_diff + weight_offset * g);
            == (see https://github.com/BVLC/caffe/blob/master/src/caffe/util/math_functions.cu#L16)
            cublasSgemm(CUBLAS_OP_T, CUBLAS_OP_N, K_, M_, N_,
                1.0,
                col_data + col_offset * g, N_,
                top_diff + top[i]->offset(n) + top_offset * g, N_,
                1.0,
                weight_diff + weight_offset * g, K_);
          }
        }
        */
    }
    else if (direction == 2) {  // backprop wrt. inputs
        output = bottom;
        // bottom is set to zero here rather than inside of col2im
        PyArray_FILLWBYTE(bottom, 0);
        // full convolution: gemm, then col2im
        // Iterate over batch

        int blas_threads_saved = 0;
        // Always forcing gemm to one thread when OpenMP is enalbed for best and stable performance.
        (1);
        
        for (int n = 0; n < batchSize; ++n) {
            // gemm into columns
            int tid = 0;
            sgemm_(&NTrans, &Trans,
                   &N_, &K_, &M_,
                   &one,
                   (npy_float*)PyArray_DATA(top) + n * top_stride, &N_,
                   (npy_float*)PyArray_DATA(weight), &K_,
                   &zero,
                   (npy_float*)PyArray_DATA(col) + tid * col_stride, &N_);
            // col2im back to the data
            col2im((npy_float*)PyArray_DATA(col) + tid * col_stride, nChannels, bottomHeight, bottomWidth,
                   kH, kW, dilH, dilW, padH, padW,
                   dH, dW, (npy_float*)PyArray_DATA(bottom) + n * bottom_stride);
        }
        // Restore to previous blas threads
        (blas_threads_saved);
        /*
        // Original caffe code for comparison
        // Note that this code was translated from the Theano GPU code,
        // not the Caffe CPU code.
        // https://github.com/BVLC/caffe/blob/master/src/caffe/layers/conv_layer.cu
        for (int n = 0; n < num_; ++n) {
          // gradient w.r.t. bottom data, if necessary
          if (propagate_down[i]) {
            for (int g = 0; g < group_; ++g) {
              caffe_gpu_gemm<Dtype>(CblasTrans, CblasNoTrans, K_, N_, M_,
                  (Dtype)1., weight + weight_offset * g,
                  top_diff + top[i]->offset(n) + top_offset * g,
                  (Dtype)0., col_diff + col_offset * g);
              == (see https://github.com/BVLC/caffe/blob/master/src/caffe/util/math_functions.cu#L16)
              cublasSgemm(CUBLAS_OP_N, CUBLAS_OP_T, N_, K_, M_,
                  1.,
                  top_diff + top[i]->offset(n) + top_offset * g, N_,
                  weight + weight_offset * g, K_,
                  0.,
                  col_diff + col_offset * g, N_);
            }
            // col2im back to the data
            col2im_gpu(col_diff, channels_, height_, width_,
                kernel_h_, kernel_w_, pad_h_, pad_w_, stride_h_, stride_w_,
                bottom_diff + (*bottom)[i]->offset(n));
          }
        }
        */
    }
    // Free temporary columns
    Py_DECREF(col);
    // decref from contiguous check
    Py_DECREF(bottom);
    Py_DECREF(weight);
    Py_DECREF(top);

    // Note that we don't change the refcount of the output matrix here. Output
    // (re)allocation and refcounting is done in BaseCorrMM.c_code_helper();
    // in here output is just aliased to one of bottom, weights, or top.
    return output;
}



    namespace {
    struct __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d {
        PyObject* __ERROR;

        PyObject* storage_V3;
PyObject* storage_V5;
PyObject* storage_V1;
        

        __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d() {
            // This is only somewhat safe because we:
            //  1) Are not a virtual class
            //  2) Do not use any virtual classes in the members
            //  3) Deal with mostly POD and pointers

            // If this changes, we would have to revise this, but for
            // now I am tired of chasing segfaults because
            // initialization code had an error and some pointer has
            // a junk value.
            memset(this, 0, sizeof(*this));
        }
        ~__struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d(void) {
            cleanup();
        }

        int init(PyObject* __ERROR, PyObject* storage_V3, PyObject* storage_V5, PyObject* storage_V1) {
            Py_XINCREF(storage_V3);
Py_XINCREF(storage_V5);
Py_XINCREF(storage_V1);
            this->storage_V3 = storage_V3;
this->storage_V5 = storage_V5;
this->storage_V1 = storage_V1;
            




            this->__ERROR = __ERROR;
            return 0;
        }
        void cleanup(void) {
            __label_1:

double __DUMMY_1;
__label_3:

double __DUMMY_3;
__label_5:

double __DUMMY_5;
__label_8:

double __DUMMY_8;

            Py_XDECREF(this->storage_V3);
Py_XDECREF(this->storage_V5);
Py_XDECREF(this->storage_V1);
        }
        int run(void) {
            int __failure = 0;
            
    PyObject* py_V1;
    
        PyArrayObject* V1;
        
            typedef npy_float32 dtype_V1;
            
    PyObject* py_V3;
    
        PyArrayObject* V3;
        
            typedef npy_float32 dtype_V3;
            
    PyObject* py_V5;
    
        PyArrayObject* V5;
        
            typedef npy_float32 dtype_V5;
            
{

    py_V1 = PyList_GET_ITEM(storage_V1, 0);
    {Py_XINCREF(py_V1);}
    
        if (py_V1 == Py_None)
        {
            
        V1 = NULL;
        
        }
        else
        {
            
            V1 = NULL;
            if (py_V1 == Py_None) {
                // We can either fail here or set V1 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            if (!PyArray_Check(py_V1)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V1;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V1) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V1));
                {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
            }
            
        V1 = (PyArrayObject*)(py_V1);
        Py_XINCREF(V1);
        
        }
        
{

    py_V3 = PyList_GET_ITEM(storage_V3, 0);
    {Py_XINCREF(py_V3);}
    
            V3 = NULL;
            if (py_V3 == Py_None) {
                // We can either fail here or set V3 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            if (!PyArray_Check(py_V3)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V3)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V3;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V3),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V3) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V3));
                {
        __failure = 4;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_4;}
            }
            
        V3 = (PyArrayObject*)(py_V3);
        Py_XINCREF(V3);
        
{

    py_V5 = PyList_GET_ITEM(storage_V5, 0);
    {Py_XINCREF(py_V5);}
    
            V5 = NULL;
            if (py_V5 == Py_None) {
                // We can either fail here or set V5 to NULL and rely on Ops
                // using tensors to handle the NULL case, but if they fail to do so
                // they'll end up with nasty segfaults, so this is public service.
                PyErr_SetString(PyExc_ValueError, "expected an ndarray, not None");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            if (!PyArray_Check(py_V5)) {
                PyErr_SetString(PyExc_ValueError, "expected an ndarray");
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            // We expect NPY_FLOAT32
            if (!PyArray_ISALIGNED((PyArrayObject*) py_V5)) {
                PyArrayObject * tmp = (PyArrayObject*) py_V5;
                PyErr_Format(PyExc_NotImplementedError,
                             "expected an aligned array of type %ld "
                             "(NPY_FLOAT32), got non-aligned array of type %ld"
                             " with %ld dimensions, with 3 last dims "
                             "%ld, %ld, %ld"
                             " and 3 last strides %ld %ld, %ld.",
                             (long int) NPY_FLOAT32,
                             (long int) PyArray_TYPE((PyArrayObject*) py_V5),
                             (long int) PyArray_NDIM(tmp),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_DIMS(tmp)[PyArray_NDIM(tmp)-1] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 3 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-3] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 2 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-2] : -1),
                             (long int) (PyArray_NDIM(tmp) >= 1 ?
            PyArray_STRIDES(tmp)[PyArray_NDIM(tmp)-1] : -1)
            );
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            // This is a TypeError to be consistent with DEBUG_MODE
            // Note: DEBUG_MODE also tells the name of the container
            if (PyArray_TYPE((PyArrayObject*) py_V5) != NPY_FLOAT32) {
                PyErr_Format(PyExc_TypeError,
                             "expected type_num %d (NPY_FLOAT32) got %d",
                             NPY_FLOAT32, PyArray_TYPE((PyArrayObject*) py_V5));
                {
        __failure = 6;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_6;}
            }
            
        V5 = (PyArrayObject*)(py_V5);
        Py_XINCREF(V5);
        
{
// Op class CorrMM

    // Mandatory args
    int direction = 0;  // forward, bprop weights, bprop inputs

    // Optional args
    int dH = 1;
    int dW = 1;
    int dilH = 1;
    int dilW = 1;
    int padH = 0;
    int padW = 0;

    PyArrayObject * bottom = V3;
    PyArrayObject * weights = V5;
    PyArrayObject * top = V1;
    PyArrayObject * out2 = NULL;

    // Obtain or infer kernel width and height
    // (we need to know it early to be able to handle auto-padding)
    int kH, kW, dil_kH, dil_kW;
    if (direction != 1) {
        // weight is an input variable, we can just read its shape
        kH = PyArray_DIMS(weights)[2];
        kW = PyArray_DIMS(weights)[3];
    }
    else {
        if (-1 != -1) {
            // kernel height is specified (perhaps vertical subsampling or half padding)
            kH = -1;
        }
        else if (padH == -2) {
            // vertical full padding, we can infer the kernel height
            kH = (2 - PyArray_DIMS(bottom)[2] + (PyArray_DIMS(top)[2] - 1) * dH - 1)/ dilH + 1;
        }
        else {
            // explicit padding, we can infer the kernel height
            kH = (PyArray_DIMS(bottom)[2] + 2*padH - (PyArray_DIMS(top)[2] - 1) * dH - 1) / dilH +1;
        }
        if (-1 != -1) {
            // kernel width is specified (perhaps horizontal subsampling or half padding)
            kW = -1;
        }
        else if (padW == -2) {
            kW = (2 - PyArray_DIMS(bottom)[3] + (PyArray_DIMS(top)[3] - 1) * dW - 1) / dilW + 1;
        }
        else {
            kW = (PyArray_DIMS(bottom)[3] + 2*padW - (PyArray_DIMS(top)[3] - 1) * dW - 1) / dilW + 1;
        }
    }

    // Implicit dilated kernel size
    dil_kH = (kH - 1) * dilH + 1;
    dil_kW = (kW - 1) * dilW + 1;

    // Auto-padding if requested
    if (padH == -1) {  // vertical half padding
        padH = dil_kH / 2;
    }
    else if (padH == -2) {  // vertical full padding
        padH = dil_kH - 1;
    }
    else if (padH < 0) {
        PyErr_SetString(PyExc_ValueError, "BaseCorrMM: padH must be >= -2");
        {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
    }
    if (padW == -1) {  // horizontal half padding
        padW = dil_kW / 2;
    }
    else if (padW == -2) {  // horizontal full padding
        padW = dil_kW - 1;
    }
    else if (padW < 0) {
        PyErr_SetString(PyExc_ValueError, "BaseCorrMM: padW must be >= -2");
        {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
    }

    // Infer output shape
    npy_intp out_dim[4];
    switch(direction) {
    case 0:  // forward pass
        // output is top: (batchsize, num_filters, height, width)
        // height and width: top = (bottom + 2*pad - ((weight-1)*dil + 1)) / sample + 1
        out_dim[0] = (npy_intp)PyArray_DIMS(bottom)[0];
        out_dim[1] = (npy_intp)PyArray_DIMS(weights)[0];
        out_dim[2] = (npy_intp)((PyArray_DIMS(bottom)[2] + 2*padH - ((PyArray_DIMS(weights)[2]-1)*dilH + 1)) / dH + 1);
        out_dim[3] = (npy_intp)((PyArray_DIMS(bottom)[3] + 2*padW - ((PyArray_DIMS(weights)[3]-1)*dilW + 1)) / dW + 1);
        if (out_dim[0] < 0 || out_dim[1] < 0 || out_dim[2] <= 0 || out_dim[3] <= 0)
        {
            PyErr_Format(PyExc_ValueError,
                         "CorrMM: impossible output shape\n"
                         "  bottom shape: %ld x %ld x %ld x %ld\n"
                         "  weights shape: %ld x %ld x %ld x %ld\n"
                         "  top shape: %ld x %ld x %ld x %ld\n",
                         (long int)PyArray_DIMS(bottom)[0], (long int)PyArray_DIMS(bottom)[1],
                         (long int)PyArray_DIMS(bottom)[2], (long int)PyArray_DIMS(bottom)[3],
                         (long int)PyArray_DIMS(weights)[0], (long int)PyArray_DIMS(weights)[1],
                         (long int)PyArray_DIMS(weights)[2], (long int)PyArray_DIMS(weights)[3],
                         (long int)out_dim[0], (long int)out_dim[1], (long int)out_dim[2],
                         (long int)out_dim[3]);
            {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
        }
        break;
    case 1:  // backprop wrt. weights
        // output is weights: (num_filters, num_channels, height, width)
        // height and width: weights = (bottom + 2*pad - (top - 1) * sample - 1) / dil + 1
        out_dim[0] = (npy_intp)PyArray_DIMS(top)[1];
        out_dim[1] = (npy_intp)PyArray_DIMS(bottom)[1];
        out_dim[2] = (npy_intp)kH;  // already inferred further above
        out_dim[3] = (npy_intp)kW;  // how convenient
        if (out_dim[0] < 0 || out_dim[1] < 0 || out_dim[2] <= 0 || out_dim[3] <= 0)
        {
            PyErr_Format(PyExc_ValueError,
                         "CorrMM backprop wrt. weights: impossible output shape\n"
                         "  bottom shape: %ld x %ld x %ld x %ld\n"
                         "  weights shape: %ld x %ld x %ld x %ld\n"
                         "  top shape: %ld x %ld x %ld x %ld\n",
                         (long int)PyArray_DIMS(bottom)[0], (long int)PyArray_DIMS(bottom)[1],
                         (long int)PyArray_DIMS(bottom)[2], (long int)PyArray_DIMS(bottom)[3],
                         (long int)out_dim[0], (long int)out_dim[1], (long int)out_dim[2],
                         (long int)out_dim[3],
                         (long int)PyArray_DIMS(top)[0], (long int)PyArray_DIMS(top)[1],
                         (long int)PyArray_DIMS(top)[2], (long int)PyArray_DIMS(top)[3]);
            {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
        }
        break;
    case 2:  // backprop wrt. inputs
        // output is bottom: (batchsize, num_channels, height, width)
        // height and width: bottom = (top - 1) * sample + (weights-1)*dil + 1 - 2*pad
        out_dim[0] = (npy_intp)PyArray_DIMS(top)[0];
        out_dim[1] = (npy_intp)PyArray_DIMS(weights)[1];
        out_dim[2] = (npy_intp)((-1 != -1) ? -1 : (PyArray_DIMS(top)[2] - 1) * dH + (PyArray_DIMS(weights)[2]-1)*dilH + 1 - 2*padH);
        out_dim[3] = (npy_intp)((-1 != -1) ? -1 : (PyArray_DIMS(top)[3] - 1) * dW + (PyArray_DIMS(weights)[3]-1)*dilW + 1 - 2*padW);
        if (out_dim[0] < 0 || out_dim[1] < 0 || out_dim[2] <= 0 || out_dim[3] <= 0)
        {
            PyErr_Format(PyExc_ValueError,
                         "CorrMM backprop wrt. inputs: impossible output shape\n"
                         "  bottom shape: %ld x %ld x %ld x %ld\n"
                         "  weights shape: %ld x %ld x %ld x %ld\n"
                         "  top shape: %ld x %ld x %ld x %ld\n",
                         (long int)out_dim[0], (long int)out_dim[1], (long int)out_dim[2],
                         (long int)out_dim[3],
                         (long int)PyArray_DIMS(weights)[0], (long int)PyArray_DIMS(weights)[1],
                         (long int)PyArray_DIMS(weights)[2], (long int)PyArray_DIMS(weights)[3],
                         (long int)PyArray_DIMS(top)[0], (long int)PyArray_DIMS(top)[1],
                         (long int)PyArray_DIMS(top)[2], (long int)PyArray_DIMS(top)[3]);
            {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
        }
        break;
    default:
        PyErr_SetString(PyExc_ValueError, "BaseCorrMM: direction must be 0, 1, or 2\n");
        {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
    }

    // Prepare output array
    int typenum;
    if ( !(V1
           && PyArray_NDIM(V1)==4
           && PyArray_IS_C_CONTIGUOUS(V1)
           && PyArray_DIMS(V1)[0]==out_dim[0]
           && PyArray_DIMS(V1)[1]==out_dim[1]
           && PyArray_DIMS(V1)[2]==out_dim[2]
           && PyArray_DIMS(V1)[3]==out_dim[3]))
    {
        Py_XDECREF(V1);
        if (direction != 1) {
          typenum = PyArray_TYPE(weights);
        }
        else {
          typenum = PyArray_TYPE(bottom);
        }
        //Change to PyArray_ZEROS which is faster than PyArray_EMPTY.
        V1 = (PyArrayObject*)PyArray_ZEROS(4,
                                          out_dim,
                                          typenum,
                                          0);
        if (NULL == V1)
        {
            PyErr_Format(PyExc_RuntimeError,
                    "BaseCorrMM: Failed to allocate output of %lld x %lld x %lld x %lld",
                    (long long)out_dim[0], (long long)out_dim[1], (long long)out_dim[2], (long long)out_dim[3]);
            {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
        }
    }

    // Call corrMM code
    out2 = corrMM(V3, V5, V1, direction, dH, dW, dilH, dilW, padH, padW);
    if (out2==NULL){
       {
        __failure = 7;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_7;}
    }
    assert (out2 == V1);

__label_7:

double __DUMMY_7;

}
__label_6:

        if (V5) {
            Py_XDECREF(V5);
        }
        
    {Py_XDECREF(py_V5);}
    
double __DUMMY_6;

}
__label_4:

        if (V3) {
            Py_XDECREF(V3);
        }
        
    {Py_XDECREF(py_V3);}
    
double __DUMMY_4;

}
__label_2:

    if (!__failure) {
      
        {Py_XDECREF(py_V1);}
        if (!V1) {
            Py_INCREF(Py_None);
            py_V1 = Py_None;
        }
        else if ((void*)py_V1 != (void*)V1) {
            py_V1 = (PyObject*)V1;
        }

        {Py_XINCREF(py_V1);}

        if (V1 && !PyArray_ISALIGNED((PyArrayObject*) py_V1)) {
            PyErr_Format(PyExc_NotImplementedError,
                         "c_sync: expected an aligned array, got non-aligned array of type %ld"
                         " with %ld dimensions, with 3 last dims "
                         "%ld, %ld, %ld"
                         " and 3 last strides %ld %ld, %ld.",
                         (long int) PyArray_TYPE((PyArrayObject*) py_V1),
                         (long int) PyArray_NDIM(V1),
                         (long int) (PyArray_NDIM(V1) >= 3 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-3] : -1),
                         (long int) (PyArray_NDIM(V1) >= 2 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-2] : -1),
                         (long int) (PyArray_NDIM(V1) >= 1 ?
        PyArray_DIMS(V1)[PyArray_NDIM(V1)-1] : -1),
                         (long int) (PyArray_NDIM(V1) >= 3 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-3] : -1),
                         (long int) (PyArray_NDIM(V1) >= 2 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-2] : -1),
                         (long int) (PyArray_NDIM(V1) >= 1 ?
        PyArray_STRIDES(V1)[PyArray_NDIM(V1)-1] : -1)
        );
            {
        __failure = 2;
        if (!PyErr_Occurred()) {
            PyErr_SetString(PyExc_RuntimeError,
                "Unexpected error in an Op's C code. "
                "No Python exception was set.");
            }
        goto __label_2;}
        }
        
      PyObject* old = PyList_GET_ITEM(storage_V1, 0);
      {Py_XINCREF(py_V1);}
      PyList_SET_ITEM(storage_V1, 0, py_V1);
      {Py_XDECREF(old);}
    }
    
        if (V1) {
            Py_XDECREF(V1);
        }
        
    {Py_XDECREF(py_V1);}
    
double __DUMMY_2;

}

            
        if (__failure) {
            // When there is a failure, this code puts the exception
            // in __ERROR.
            PyObject* err_type = NULL;
            PyObject* err_msg = NULL;
            PyObject* err_traceback = NULL;
            PyErr_Fetch(&err_type, &err_msg, &err_traceback);
            if (!err_type) {err_type = Py_None;Py_INCREF(Py_None);}
            if (!err_msg) {err_msg = Py_None; Py_INCREF(Py_None);}
            if (!err_traceback) {err_traceback = Py_None; Py_INCREF(Py_None);}
            PyObject* old_err_type = PyList_GET_ITEM(__ERROR, 0);
            PyObject* old_err_msg = PyList_GET_ITEM(__ERROR, 1);
            PyObject* old_err_traceback = PyList_GET_ITEM(__ERROR, 2);
            PyList_SET_ITEM(__ERROR, 0, err_type);
            PyList_SET_ITEM(__ERROR, 1, err_msg);
            PyList_SET_ITEM(__ERROR, 2, err_traceback);
            {Py_XDECREF(old_err_type);}
            {Py_XDECREF(old_err_msg);}
            {Py_XDECREF(old_err_traceback);}
        }
        // The failure code is returned to index what code block failed.
        return __failure;
        
        }
    };
    }
    

        static int __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d_executor(__struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d *self) {
            return self->run();
        }

        static void __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d_destructor(PyObject *capsule) {
            __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d *self = (__struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d *)PyCapsule_GetContext(capsule);
            delete self;
        }
        
//////////////////////
////  Functions
//////////////////////
static PyObject * instantiate(PyObject * self, PyObject *argtuple) {
  assert(PyTuple_Check(argtuple));
  if (4 != PyTuple_Size(argtuple)){ 
     PyErr_Format(PyExc_TypeError, "Wrong number of arguments, expected 4, got %i", (int)PyTuple_Size(argtuple));
     return NULL;
  }
  __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d* struct_ptr = new __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d();
  if (struct_ptr->init( PyTuple_GET_ITEM(argtuple, 0),PyTuple_GET_ITEM(argtuple, 1),PyTuple_GET_ITEM(argtuple, 2),PyTuple_GET_ITEM(argtuple, 3) ) != 0) {
    delete struct_ptr;
    return NULL;
  }
    PyObject* thunk = PyCapsule_New((void*)(&__struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d_executor), NULL, __struct_compiled_op_m6b3a665fbdb3a8655b39de3eaeafa37d_destructor);
    if (thunk != NULL && PyCapsule_SetContext(thunk, struct_ptr) != 0) {
        PyErr_Clear();
        Py_DECREF(thunk);
        thunk = NULL;
    }

  return thunk; }

//////////////////////
////  Module init
//////////////////////
static PyMethodDef MyMethods[] = {
	{"instantiate", instantiate, METH_VARARGS, "undocumented"} ,
	{NULL, NULL, 0, NULL}
};
static struct PyModuleDef moduledef = {
      PyModuleDef_HEAD_INIT,
      "m6b3a665fbdb3a8655b39de3eaeafa37d",
      NULL,
      -1,
      MyMethods,
};

PyMODINIT_FUNC PyInit_m6b3a665fbdb3a8655b39de3eaeafa37d(void) {
   import_array();
    PyObject *m = PyModule_Create(&moduledef);
    return m;
}
