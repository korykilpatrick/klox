#ifndef klox_vm_h
#define klox_vm_h

#include "chunk.h"
#include "table.h"
#include "value.h"

// giving VM fixed stack size means we risk stack overflow,
// but its simpler than growing stack dynamically
#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
  uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop; // points to where next value to be pushed will go
  Table globals;
  Table strings;
  
  Obj* objects;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpet(const char* source);
void push(Value value);
Value pop();

#endif