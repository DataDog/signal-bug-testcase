require 'signal_bug_testcase'

Signal.trap("TERM") { puts "Hello, world" }

FOO = SignalBugTestcase.new
