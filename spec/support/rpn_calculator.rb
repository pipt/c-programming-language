module RpnCalculator
  def calc(input)
    calc_raw(input).to_f
  end

  def calc_raw(input)
    compile_and_run(
      "chapter-4/calculator",
      ["main", "getch", "getop", "long_commands", "stack", "variables"],
      input
    ).strip
  end
end
