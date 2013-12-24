require "tmpdir"

module CompileAndRun
  def compile(directory, name)
    Dir.mktmpdir do |dir|
      current_dir = Dir.pwd
      Dir.chdir(dir)
      source = File.expand_path("../../../#{directory}/#{name}.c", __FILE__)
      `cc -o #{name} #{source}`
      yield
      Dir.chdir(current_dir)
    end
  end

  def compile_and_run(directory, name, input)
    output = nil
    compile(directory, name) do
      output = `echo "#{input}" | ./#{name}`
    end
    output
  end

  def compile_and_run_with_args(directory, name, *args)
    output = nil
    compile(directory, name) do
      output = `./#{name} #{args.join(" ")}`
    end
    output
  end

  def compile_and_run_with_stdin_and_args(directory, name, stdin, *args)
    output = nil
    compile(directory, name) do
      output = `echo "#{stdin}" | ./#{name} #{args.join(" ")}`
    end
    output
  end
end
