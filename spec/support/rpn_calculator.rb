module RpnCalculator
  def calc(input)
    calc_raw(input).to_f
  end

  def calc_raw(input)
    compile_and_run("chapter-4/calculator", "rpn_calc", input).strip
  end
end
