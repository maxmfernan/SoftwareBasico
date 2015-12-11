#include "macros.h"

void jvmStartup(ClassFile *classHeap_ptr, Object *objectHeap_ptr, Frame *stackFrame_ptr, FILE *classPathF_ptr, dataMSize_t *dmSize_ptr);

void initializeClass(ClassFile *class_ptr, Frame *stkFrame_ptr, u2 *stkFrameTop_ptr);

u2 seekMethodInClass(ClassFile *class_ptr, char *methName_str, char *methDescriptor_str);

int findClass(ClassFile *classHeap_ptr, dataMSize_t dmSize, char* ClassName);

u2 findCode(ClassFile *Class); 

void createFrame(method_info *method, ClassFile *Class, Frame *frame_ptr, u2 *numFrames); 

void deleteFrame(Frame *frame_ptr, u2 *numFrames); 







