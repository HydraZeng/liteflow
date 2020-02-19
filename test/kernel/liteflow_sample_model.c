// The sample model code can be generated by configurator outside datapath

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/slab.h>

#include "linux/liteflow.h"

#define APP_ID LF_TEST_ID
#define MODEL_UUID 2333

// static s64 input_vector[8] = {1, 2, 3, 4, 5, 6, 7, 8};
// static s64 output_vector[6];

static void layer1_comp (s64 *input, s64 *output);
static void layer2_comp (s64 *input, s64 *output);

struct model_container sample_model __read_mostly = {
    .uuid = MODEL_UUID,
    .input_size = 8,
    .output_size = 6,
};

struct model_layer layer1 __read_mostly = {
    .uuid = 23331,
    .input_size = 8,
    .output_size = 5,
    .comp_func = layer1_comp,
};

struct model_layer layer2 __read_mostly = {
    .uuid = 23332,
    .input_size = 5,
    .output_size = 6,
    .comp_func = layer2_comp,
};

static void construct_model(void)
{
    INIT_LIST_HEAD(&sample_model.layers);
    list_add(&layer1.list, &sample_model.layers);
    list_add(&layer2.list, &layer1.list);
}

// sample code, and the code should be generated based on cadidate models from userspace
static void layer1_comp (s64 *input, s64 *output)
{
    u32 input_pos, output_pos = 0; 
    s64 temp_result = 0;

    for (output_pos = 0; output_pos < 5; ++output_pos) {
        for (input_pos = 0; input_pos < 8; ++input_pos) {
            temp_result += input[input_pos];
        }
        output[output_pos] = temp_result;
    }
}

static void layer2_comp (s64 *input, s64 *output)
{
    u32 input_pos, output_pos = 0;
    s64 temp_result = 0;
    for (output_pos = 0; output_pos < 6; output_pos ++) {
        for (input_pos = 0; input_pos < 5; input_pos++) {
            temp_result += input[input_pos];
        }
        output[output_pos] = temp_result;
    }
}

struct app app = {
    .appid = APP_ID,
    .input_size = 8,
    .output_size = 6,
};

static int
__init liteflow_sample_model_init(void)
{
    // u32 pos;

    lf_register_app(&app);

    construct_model();
    lf_register_model(APP_ID, &sample_model);
    // lf_activate_model(APP_ID, MODEL_UUID); // 2333 active
    // lf_query_model(APP_ID, input_vector, output_vector); // No active model

    // printk(KERN_INFO "Sample output:\n");
    // for (pos = 0; pos < 6; ++pos) {
    //     printk(KERN_INFO "pos %u: %lld\n", pos, output_vector[pos]);
    // }
    return 0;
}

static void
__exit liteflow_sample_model_exit(void)
{
    lf_unregister_app(APP_ID);
}

module_init(liteflow_sample_model_init);
module_exit(liteflow_sample_model_exit);

MODULE_DESCRIPTION("liteflow sample model");
MODULE_AUTHOR("Junxue ZHANG");
MODULE_LICENSE("GPL v2");