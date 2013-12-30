require "tmpdir"

module CompileAndRun
  def compile(directory, names)
    Dir.mktmpdir do |dir|
      current_dir = Dir.pwd
      Dir.chdir(dir)
      sources = Array(names).map { |name|
        File.expand_path("../../../#{directory}/#{name}.c", __FILE__)
      }
      `cc -o #{program_name(names)} #{sources.join(" ")}`
      yield
      Dir.chdir(current_dir)
    end
  end

  def program_name(names)
    Array(names).first
  end

  def compile_and_run(directory, names, input = nil)
    output = nil
    compile(directory, names) do
      output = `echo "#{input}" | ./#{program_name(names)}`
    end
    output
  end

  def compile_and_run_with_args(directory, names, *args)
    output = nil
    compile(directory, names) do
      output = `./#{program_name(names)} #{args.join(" ")}`
    end
    output
  end

  def compile_and_run_with_stdin_and_args(directory, names, stdin, *args)
    output = nil
    compile(directory, names) do
      output = `echo "#{stdin}" | ./#{program_name(names)} #{args.join(" ")}`
    end
    output
  end
end
