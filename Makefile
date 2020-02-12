SHELL := /bin/bash

MODULENAME := lf_kernel
SAMPLEAPP := lf_sample_app
SAMPLEMODEL := lf_sample_model
AURORAMODEL := lf_aurora_model

module:
		-@mkdir build
		@cp -Rf datapath build
		@cp -Rf include build
		@cd build/datapath; make all;

module_install:
		@cd build/datapath; sudo insmod $(MODULENAME).ko

module_remove:
		sudo rmmod $(MODULENAME)

sample_app_install:
		@cd build/datapath; sudo insmod $(SAMPLEAPP).ko

sample_app_remove:
		sudo rmmod $(SAMPLEAPP)

sample_model_install:
		@cd build/datapath; sudo insmod $(SAMPLEMODEL).ko

sample_model_remove:
		sudo rmmod $(SAMPLEMODEL)

aurora_model_install:
		@cd build/datapath; sudo insmod $(AURORAMODEL).ko

sample_model_remove:
		sudo rmmod $(AURORAMODEL)

clean:
		-@rm -rf build
