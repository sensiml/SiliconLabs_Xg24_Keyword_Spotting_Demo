#ifndef __SENSIML_RECOGNITION_RUN_H__
#define __SENSIML_RECOGNITION_RUN_H__



int32_t sml_recognition_run(signed short *data_batch, int32_t batch_sz, uint8_t num_sensors, uint32_t sensor_id);
int32_t sml_recognition_run_single(signed short *data, uint32_t sensor_id);

#endif //__SENSIML_RECOGNITION_RUN_H__
