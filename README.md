# LiteFlow

LiteFlow is a framework to embed a trained neural network into Linux kernel datapath with predictable performance. It provides API to automatically deploy and compress if needed a neural network trained with TensorFlow (We are supporting more!) in user space to Linux kernel. LiteFlow also provides standard API to make the deployed neural networks to interact with Linux kernel datapath, such as TCP congestion control (We are supporting more). LiteFlow also exposes standard API to user space for collecting data used in online learning.

The key of LiteFlow is to provide predictable performance neural network for Linux kernel datapath without the ease to train and re-train model in user space. LiteFlow uses performance centric model compression techniques to make the trained neural network suitable for Linux kernel, and dynamically load the model into the kernel. LiteFlow also provides model rollback functions to ensure the correctness of datapath.

[![Build Status](https://travis-ci.org/liteflow/liteflow.svg?branch=master)](https://travis-ci.org/liteflow/liteflow)

## Building LiteFlow

1. Clone the whole repo.

```
git clone git@github.com:liteflow/liteflow.git
```

2. Build LiteFlow

```
make all
```

The command will sequentially invoke:

```make clean``` to clean the workspace.

```make module ``` to make kernel modules.

```make lib``` to make userspace modules.

```make test``` to make test binaries.

3. Install kernel module

```
make module_install
```
to install LiteFlow general kernel.

If you would like to use LiteFlow with TCP congestion control, you should also install LiteFlow TCP kernel.
```
make tcp_kernel_install
```

4. Install user space library

```
make lib_install
```

5. Install python library

6. Let's GO!!!

## Test

TBD

## Contibution

TBD
