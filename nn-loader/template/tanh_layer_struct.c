struct model_layer layer_{{ prefix }} __read_mostly = {
    .uuid = {{ uuid }},
    .input_size = {{ input_size }},
    .output_size = {{ output_size }},
    .comp_func = tanh_{{ prefix }}_comp,
};