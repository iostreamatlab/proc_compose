/*
 * =====================================================================================
 *
 *       Filename:  Compose.c
 *
 *    Description:  Proc composition
 *
 *        Version:  1.0
 *        Created:  10/01/2016 16:14:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alex Moore-Niemi
 *
 * =====================================================================================
 */

#include <ruby.h>

// Defining a space for information and references about the module to be stored internally
VALUE Compose = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_compose();

VALUE compose(VALUE arg, VALUE procs) {
	VALUE first = rb_ary_entry(procs, 0);
	VALUE second = rb_ary_entry(procs, 1);

	// allocates too many intermediate arrays
	//return rb_proc_call(second, rb_ary_new3(1, rb_proc_call(first, rb_ary_new3(1, arg))));
	VALUE first_result = rb_funcall(first, rb_intern("call"), 1, arg);
	VALUE final_result = rb_funcall(second, rb_intern("call"), 1, first_result);

	return final_result;
}

VALUE method_compose(VALUE self, VALUE other_proc) {
	VALUE procs = other_proc;
	procs = rb_ary_push(procs, self);
	VALUE result = rb_proc_new(compose, procs);

	//	FILE *f = fopen("clog.txt", "w");
	//	fprintf(f, "procs: %s\n", RSTRING_PTR(rb_ary_to_s(procs)));

	return result;
}

// The initialization method for this module
void Init_compose() {
	rb_define_method(rb_cProc, "compose", method_compose, -2);
	rb_define_method(rb_cProc, "*", method_compose, -2);
}
