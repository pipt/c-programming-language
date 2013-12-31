require "spec_helper"

describe "tail" do
  def run(stdin, *args)
    compile_and_run_with_stdin_and_args("chapter-5", "tail", stdin, *args).strip
  end

  def lines(n)
    (1..n).map(&:to_s).join("\n")
  end

  it "prints 10 lines when no arguments given" do
    expect(run(lines(20))).to eq(lines(10))
  end

  it "prints the correct number of lines when arguments given" do
    expect(run(lines(20), "-16")).to eq(lines(16))
  end
end
