
/* ----------------------------------------------------------------------
* Copyright (c) 2022 SensiML Corporation
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* ---------------------------------------------------------------------- */


#ifndef _KB_TYPEDEFS_H_
#define _KB_TYPEDEFS_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef float FLOAT;
typedef unsigned short NORMTYPE;

// clang-format off

/*
Expected sensor column ordering for each model

#define CHANNEL_0_S_P_1_FOLD_0 0

*/

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    int16_t *data; // Array to columns to use
    int size;  // Total number of columns
} int16_data_t;

typedef struct
{
    float *data; // Array to params to use
    int size;  // Total number of params
} float_data_t;

struct compx
{
    float real;
    float imag;
};

struct compx_int16_t
{
    int16_t real;
    int16_t imag;
};



/** @struct model_results
 *  @brief This structure is used to get the output of the classifier before the classification
 *  @var typeID: the type of data stored in the feature vector
 *  @var size: The size of the data
 *  @var data: pointer to the data array
 */
typedef struct{
    uint8_t typeID; // 0 uint8_t, 1 int8_t, 2 uint16_t, 3 int16_t, 4 uint32_t, 5 int32_t, 6 float
    uint16_t size; // number of elements in the feature vector
    void * data; // pointer to the feature vector
} feature_vector_t;




/** @struct model_results
 *  @brief This structure is used to get the output of the classifier before the classification
 *  @var model_type: the type of model that is putting the results
 *  @var result: the output of the model
 *  @var output_tensor: output array from the model that stores information about classification, such as class probabilities
 */
typedef struct model_results
{
	uint8_t model_type;
    float result;
    float_data_t *output_tensor; // the output tensor results
} model_results_t;



typedef struct
{
    uint16_t influence; //influence of a pattern
    uint16_t category;  //category of pattern
    uint8_t *vector;    // vector containing the features of a pattern
} pme_pattern_t;

typedef struct
{
    uint16_t number_patterns; //influence of a pattern
    uint16_t pattern_length;  //category of pattern
} pme_model_header_t;



#ifdef __cplusplus
}
#endif
// clang-format on

#endif //_KB_TYPEDEFS_H_
