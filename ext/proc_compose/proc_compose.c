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

void Init_compose();

VALUE compose(VALUE arg, VALUE procs) {
	VALUE first = rb_ary_entry(procs, 0);
	VALUE second = rb_ary_entry(procs, 1);

	VALUE first_result = rb_funcall(first, rb_intern("call"), 1, arg);
	VALUE final_result = rb_funcall(second, rb_intern("call"), 1, first_result);

	return final_result;
}

VALUE method_compose(VALUE self, VALUE other_proc) {
	VALUE procs = other_proc;
	procs = rb_ary_push(procs, self);
	VALUE result = rb_proc_new(compose, procs);

	return result;
}

void Init_compose() {
	rb_define_method(rb_cProc, "compose", method_compose, -2);
	rb_define_method(rb_cProc, "*", method_compose, -2);
}
