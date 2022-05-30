#ifndef ENGINE_ENGINEFORWARD_H
#define ENGINE_ENGINEFORWARD_H

//
// Some classes are currently taking an instance of the engine in order
// to access attributes of the engine (they shouldn't but this is just
// what the current design limitations call for, engine components should
// really be as completely encapsulated as possible). This results in an
// error in the engine's header file, where a class depends on Engine
// which results in the class being referenced before it has been defined.
// We could forward declare all of these classes inside the engine, but then
// we can only use pointers to these objects which doesn't help us here because
// we need to initialise these objects inside the engine class. To get around
// this, we can forward declare the engine and use that in classes which take
// a pointer to the engine as an initialisation member.
// 

class Engine;

#endif // ENGINE_ENGINEFORWARD_H
