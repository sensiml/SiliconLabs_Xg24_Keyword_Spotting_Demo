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



#ifndef _KB_DEBUG_H_
#define _KB_DEBUG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include "kb_typedefs.h"
#include "kb_defines.h"
#include "kb.h"

/**
* @brief Generates a string containing the model result information
*
* @param[in] model_index Model index to use
* @param[in] result result from most recent classification
* @param[in] pbuf char buffer to hold the string
* @param[in] feature_vector a bool, true to add feature vector information
* @param[in] fv_arr an arrary to store the feature vector results in
* @returns length of data put into pbuf
*/
int32_t kb_sprint_model_result(int32_t model_index, char *pbuf, bool segment_info, bool feature_vectors, bool output_tensor);

/**
* @brief Fills a string with a json of the model output tensor
*
* @param[in] model_index Model index to use
* @param[in] result result from most recent classification
* @param[in] pbuf char buffer to hold the string
* @returns length of data put into pbuf
*/
int32_t kb_sprint_model_output_tensor(int32_t model_index, char *pbuf);


/**
* @brief Prints the model class map to a char string
*
* @param[in] model_index Model index to use
*/
void kb_print_model_class_map(int32_t model_index, char *output);
#define sml_print_model_class_map kb_print_model_class_map

void kb_print_model_map();

int32_t kb_sprint_model_cycles(
int32_t model_index, char *pbuf, uint32_t *cycles);
int32_t kb_sprint_model_times(
int32_t model_index, char *pbuf, float *times);

#ifdef __cplusplus
}
#endif

#endif // _KB_DEBUG_H_
