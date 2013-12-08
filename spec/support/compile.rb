module CompileAndRun
  def compile(directory, name)
    source = File.expand_path("../../../#{directory}/#{name}.c", __FILE__)
    `cc -o #{name} #{source}`
  end

  def compile_and_run(directory, name, input)
    compile(directory, name)
    `echo "#{input}" | ./#{name}`
  end
end
