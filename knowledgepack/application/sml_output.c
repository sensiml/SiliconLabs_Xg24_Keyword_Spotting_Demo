#include "sml_output.h"
#include "kb_output.h"
#include "kb.h"

#define SERIAL_OUT_CHARS_MAX 2056

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

// Test to see if code is being used
static char serial_out_buf[SERIAL_OUT_CHARS_MAX];
#if SML_PROFILER
float recent_fv_times[MAX_VECTOR_SIZE];
uint32_t recent_fv_cycles[MAX_VECTOR_SIZE];
#endif

static void sml_output_serial(uint16_t model)
{
    memset(serial_out_buf, 0, SERIAL_OUT_CHARS_MAX);

    kb_sprint_model_result(model, serial_out_buf, false, false, true);

    printf("%s\n", serial_out_buf);
#if SML_PROFILER
    memset(serial_out_buf, 0, SERIAL_OUT_CHARS_MAX);
    kb_print_model_cycles(model, serial_out_buf, recent_fv_cycles);
    printf("%s\n", serial_out_buf);
    memset(serial_out_buf, 0, SERIAL_OUT_CHARS_MAX);
    kb_print_model_times(model, serial_out_buf, recent_fv_times);
    printf("%s\n", serial_out_buf);
#endif
}

uint32_t sml_output_results(uint16_t model, uint16_t classification)
{
    memset(serial_out_buf, 0, SERIAL_OUT_CHARS_MAX);
    sml_output_serial(model);

    return 0;
}

uint32_t sml_output_init(void *p_module)
{
    // unused for now
    return 0;
}
