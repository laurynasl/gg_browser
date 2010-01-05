#include "ruby.h"

static VALUE sandbox_say(VALUE obj, VALUE str) {
  VALUE s = rb_funcall2(str, rb_intern("to_s"), 0, 0);
  printf(StringValueCStr(s));
  return Qnil;
}

void Init_sandbox() {
  VALUE cSandbox = rb_define_class("Sandbox", rb_cObject);
  rb_define_method(cSandbox, "say", sandbox_say, 1);
}
