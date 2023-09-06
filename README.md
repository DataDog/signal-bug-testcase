# signal-bug-testcase

Testcase for a ruby crash bug report https://bugs.ruby-lang.org/issues/19865

To trigger issue, run:

```
$ bundle install
$ bundle exec rake clean compile
$ bundle exec ruby lib/signal-bug-testcase.rb
Free getting called! Sending signal...
SIGTERM signal queued, trying to release GVL...
lib/signal-bug-testcase.rb:3: [BUG] Segmentation fault at 0x0000000000000007
ruby 3.2.2 (2023-03-30 revision e51014f9c0) [x86_64-linux]

-- Control frame information -----------------------------------------------
c:0003 p:---- s:0011 e:000010 CFUNC  :puts
c:0002 p:0005 s:0006 e:000005 BLOCK  lib/signal-bug-testcase.rb:3 [FINISH]
c:0001 p:0000 s:0003 E:0001a0 DUMMY  [FINISH]

-- Ruby level backtrace information ----------------------------------------
lib/signal-bug-testcase.rb:3:in `block in <main>'
lib/signal-bug-testcase.rb:3:in `puts'

-- Machine register context ------------------------------------------------
 RIP: 0x000070aa64cedbe7 RBP: 0x000070aa648e8fd0 RSP: 0x00007ffc5c057608
 RAX: 0x0000000000004171 RBX: 0x00007ffc5c057630 RCX: 0x0000000000000001
 RDX: 0x00007ffc5c057630 RDI: 0x0000000000000007 RSI: 0x0000000000004171
  R8: 0x000000000000021b  R9: 0x0000000000000000 R10: 0x000070aa63eff048
 R11: 0x0000000000000000 R12: 0x000070aa648e8fd0 R13: 0x0000000000004171
 R14: 0x0000000000000007 R15: 0x000070aa648e8ff0 EFL: 0x0000000000010202

-- C level backtrace information -------------------------------------------
ruby-3.2.2/lib/libruby.so.3.2(rb_print_backtrace+0xd) [0x70aa64d5bb5f] ruby-3.2.2/vm_dump.c:785
ruby-3.2.2/lib/libruby.so.3.2(rb_vm_bugreport) ruby-3.2.2/vm_dump.c:1080
ruby-3.2.2/lib/libruby.so.3.2(rb_bug_for_fatal_signal+0xf4) [0x70aa64b52164] ruby-3.2.2/error.c:813
ruby-3.2.2/lib/libruby.so.3.2(sigsegv+0x4d) [0x70aa64cab0fd] ruby-3.2.2/signal.c:964
/lib/x86_64-linux-gnu/libc.so.6(0x70aa64642520) [0x70aa64642520]
ruby-3.2.2/lib/libruby.so.3.2(hash_table_index+0x0) [0x70aa64cedbe7] ruby-3.2.2/symbol.h:72
ruby-3.2.2/lib/libruby.so.3.2(rb_id_table_lookup) ruby-3.2.2/id_table.c:230
ruby-3.2.2/lib/libruby.so.3.2(cached_callable_method_entry+0x24) [0x70aa64d356bb] ruby-3.2.2/vm_method.c:1295
ruby-3.2.2/lib/libruby.so.3.2(callable_method_entry_or_negative) ruby-3.2.2/vm_method.c:1365
ruby-3.2.2/lib/libruby.so.3.2(callable_method_entry) ruby-3.2.2/vm_method.c:1402
ruby-3.2.2/lib/libruby.so.3.2(rb_callable_method_entry) ruby-3.2.2/vm_method.c:1409
ruby-3.2.2/lib/libruby.so.3.2(gccct_method_search_slowpath+0x38) [0x70aa64d36258] ruby-3.2.2/vm_eval.c:434
ruby-3.2.2/lib/libruby.so.3.2(rb_call0+0x267) [0x70aa64d4e877] ruby-3.2.2/vm_eval.c:483
ruby-3.2.2/lib/libruby.so.3.2(rb_call+0x32) [0x70aa64d4f406] ruby-3.2.2/vm_eval.c:877
ruby-3.2.2/lib/libruby.so.3.2(rb_funcallv_kw) ruby-3.2.2/vm_eval.c:1074
ruby-3.2.2/lib/libruby.so.3.2(vm_call_cfunc_with_frame+0x127) [0x70aa64d30277] ruby-3.2.2/vm_insnhelper.c:3268
ruby-3.2.2/lib/libruby.so.3.2(vm_sendish+0x97) [0x70aa64d407a4] ruby-3.2.2/vm_insnhelper.c:5080
ruby-3.2.2/lib/libruby.so.3.2(vm_exec_core) ruby-3.2.2/insns.def:820
ruby-3.2.2/lib/libruby.so.3.2(rb_vm_exec+0xd3) [0x70aa64d460d3] ruby-3.2.2/vm.c:2374
ruby-3.2.2/lib/libruby.so.3.2(rb_vm_invoke_proc+0x5f) [0x70aa64d4bfcf] ruby-3.2.2/vm.c:1603
ruby-3.2.2/lib/libruby.so.3.2(vm_call0_body+0x5df) [0x70aa64d4c5cf] ruby-3.2.2/vm_eval.c:274
ruby-3.2.2/lib/libruby.so.3.2(vm_call0_cc+0x77) [0x70aa64d4e7e7] ruby-3.2.2/vm_eval.c:87
ruby-3.2.2/lib/libruby.so.3.2(rb_call0) ruby-3.2.2/vm_eval.c:551
ruby-3.2.2/lib/libruby.so.3.2(rb_call+0x32) [0x70aa64d4f406] ruby-3.2.2/vm_eval.c:877
ruby-3.2.2/lib/libruby.so.3.2(rb_funcallv_kw) ruby-3.2.2/vm_eval.c:1074
ruby-3.2.2/lib/libruby.so.3.2(rb_eval_cmd_kw+0x142) [0x70aa64d4f562] ruby-3.2.2/vm_eval.c:1923
ruby-3.2.2/lib/libruby.so.3.2(signal_exec+0xf6) [0x70aa64caae16] ruby-3.2.2/signal.c:1064
ruby-3.2.2/lib/libruby.so.3.2(rb_threadptr_execute_interrupts+0x36b) [0x70aa64cf7078] ruby-3.2.2/thread.c:2334
ruby-3.2.2/lib/libruby.so.3.2(rb_threadptr_execute_interrupts) ruby-3.2.2/thread.c:2291
ruby-3.2.2/lib/libruby.so.3.2(rb_vm_check_ints+0xb) [0x70aa64cf7ac5] ruby-3.2.2/vm_core.h:1994
ruby-3.2.2/lib/libruby.so.3.2(rb_vm_check_ints) ruby-3.2.2/vm_core.h:1985
ruby-3.2.2/lib/libruby.so.3.2(unblock_function_set) ruby-3.2.2/thread.c:320
ruby-3.2.2/lib/libruby.so.3.2(blocking_region_begin) ruby-3.2.2/thread.c:1485
ruby-3.2.2/lib/libruby.so.3.2(rb_nogvl+0xbf) [0x70aa64cf90cf] ruby-3.2.2/thread.c:1548
signal-bug-testcase-2/lib/signal_bug_testcase.so(fprintf+0x0) [0x70aa6518f299] ../../../../ext/signal_bug_testcase/signal_bug_testcase.c:17
signal-bug-testcase-2/lib/signal_bug_testcase.so(bug_testcase_free) ../../../../ext/signal_bug_testcase/signal_bug_testcase.c:18
ruby-3.2.2/lib/libruby.so.3.2(run_final+0xf) [0x70aa64b73172] ruby-3.2.2/gc.c:4388
ruby-3.2.2/lib/libruby.so.3.2(finalize_list) ruby-3.2.2/gc.c:4407
ruby-3.2.2/lib/libruby.so.3.2(finalize_deferred_heap_pages) ruby-3.2.2/gc.c:4436
ruby-3.2.2/lib/libruby.so.3.2(rb_objspace_call_finalizer+0x350) [0x70aa64b80d70] ruby-3.2.2/gc.c:4573
ruby-3.2.2/lib/libruby.so.3.2(rb_ec_finalize+0x2a) [0x70aa64b5d6d1] ruby-3.2.2/eval.c:168
ruby-3.2.2/lib/libruby.so.3.2(rb_ec_cleanup) ruby-3.2.2/eval.c:262
ruby-3.2.2/lib/libruby.so.3.2(ruby_run_node+0x9d) [0x70aa64b5d91d] ruby-3.2.2/eval.c:330
ruby-3.2.2/bin/ruby(rb_main+0x21) [0x5d5d1295f187] ./main.c:38
ruby-3.2.2/bin/ruby(main) ./main.c:57
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_call_main+0x80) [0x70aa64629d90] ../sysdeps/nptl/libc_start_call_main.h:58
/lib/x86_64-linux-gnu/libc.so.6(call_init+0x0) [0x70aa64629e40] ../csu/libc-start.c:392
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main_impl) ../csu/libc-start.c:379
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main) (null):0
[0x5d5d1295f1d5]
```
