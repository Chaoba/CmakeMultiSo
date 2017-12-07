# CmakeMultiSo
This project shows two ways to create our own sdk by importing a third party sdk.
The first method is to use cmake and the second one is use dlopen.

What's more, we will also need create a jni interfae for test.

There are three layers:
1. liblayer1.so -- represent a third party sdk.
2. liblayer2.so -- represent our own sdk.
3. liblayer3.so -- jni interface used for test.

