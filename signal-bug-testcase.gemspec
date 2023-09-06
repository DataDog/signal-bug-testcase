# frozen_string_literal: true

Gem::Specification.new do |spec|
  spec.name = "signal-bug-testcase"
  spec.version = '1.0.0'
  spec.authors = ["Ivo Anjo"]
  spec.email = ["ivo.anjo@datadoghq.com"]

  spec.license = "Apache-2.0"
  spec.required_ruby_version = ">= 2.6.0"
  spec.summary = 'Testcase for a Ruby VM bug. Not an actual gem.'

  spec.extensions = ["ext/signal_bug_testcase/extconf.rb"]

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files = Dir.chdir(__dir__) do
    `git ls-files -z`.split("\x0").reject do |f|
      (File.expand_path(f) == __FILE__) ||
        f.start_with?(*%w[bin/ test/ spec/ features/ .git .circleci appveyor Gemfile])
    end
  end
  spec.require_paths = ["lib"]
end
