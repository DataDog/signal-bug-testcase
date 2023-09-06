#include <ruby.h>
#include <ruby/thread.h>
#include <signal.h>
#include <unistd.h>

typedef struct { int dummy; } BugTestcase;

void *test_nogvl(void *unused) {
    fprintf(stderr, "GVL released!\n");
    return NULL;
}

static void bug_testcase_free(void* ptr) {
    fprintf(stderr, "Free getting called! Sending signal...\n");
    kill(getpid(), SIGTERM);
    fprintf(stderr, "SIGTERM signal queued, trying to release GVL...\n");
    rb_thread_call_without_gvl(test_nogvl, NULL, NULL, NULL);
    fprintf(stderr, "After releasing GVL!\n");
    free(ptr);
}

const rb_data_type_t bug_testcase_data_type = {
    .wrap_struct_name = "SignalBugTestcase",
    .function = { NULL, bug_testcase_free, NULL },
    .flags = RUBY_TYPED_FREE_IMMEDIATELY
};

VALUE bug_testcase_alloc(VALUE klass) {
    BugTestcase* obj = calloc(1, sizeof(BugTestcase));
    return TypedData_Make_Struct(klass, BugTestcase, &bug_testcase_data_type, obj);
}

void Init_signal_bug_testcase(void) {
    VALUE cBugTestcase = rb_define_class("SignalBugTestcase", rb_cObject);

    rb_define_alloc_func(cBugTestcase, bug_testcase_alloc);
}
