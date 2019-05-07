################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FilterDMA.c \
../src/ISR.c \
../src/RegisterManager.c 

CPP_SRCS += \
../src/AlgoTester.cpp \
../src/Algorithm.cpp \
../src/Application.cpp \
../src/Controller.cpp \
../src/Process.cpp \
../src/SoundFilter3D.cpp \
../src/SpatialSoundAlgo.cpp \
../src/Switch.cpp 

SRC_OBJS += \
./src/AlgoTester.doj \
./src/Algorithm.doj \
./src/Application.doj \
./src/Controller.doj \
./src/FilterDMA.doj \
./src/ISR.doj \
./src/Process.doj \
./src/RegisterManager.doj \
./src/SoundFilter3D.doj \
./src/SpatialSoundAlgo.doj \
./src/Switch.doj 

C_DEPS += \
./src/FilterDMA.d \
./src/ISR.d \
./src/RegisterManager.d 

CPP_DEPS += \
./src/AlgoTester.d \
./src/Algorithm.d \
./src/Application.d \
./src/Controller.d \
./src/Process.d \
./src/SoundFilter3D.d \
./src/SpatialSoundAlgo.d \
./src/Switch.d 


# Each subdirectory must supply rules for building sources it contributes
src/AlgoTester.doj: ../src/AlgoTester.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/AlgoTester.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Algorithm.doj: ../src/Algorithm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Algorithm.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Application.doj: ../src/Application.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Application.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Controller.doj: ../src/Controller.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Controller.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/FilterDMA.doj: ../src/FilterDMA.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/FilterDMA.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ISR.doj: ../src/ISR.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/ISR.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Process.doj: ../src/Process.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Process.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RegisterManager.doj: ../src/RegisterManager.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/RegisterManager.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SoundFilter3D.doj: ../src/SoundFilter3D.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/SoundFilter3D.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SpatialSoundAlgo.doj: ../src/SpatialSoundAlgo.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/SpatialSoundAlgo.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Switch.doj: ../src/Switch.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="DSPFramework" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision 0.6 -O -Ov100 -DCORE0 -DNDEBUG @includes-abeab206f40f3f95e7bcb3bf676934c9.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/Switch.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


