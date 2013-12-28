require "spec_helper"

describe "basic functionality" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip.to_f
  end

  it "adds" do
    expect(run("11 22 +")).to eq(33)
  end

  it "subtracts" do
    expect(run("11 22 -")).to eq(-11)
  end

  it "multiplies" do
    expect(run("11 22 *")).to eq(242)
  end

  it "divides" do
    expect(run("11 22 /")).to eq(0.5)
  end

  it "performs multiple operations" do
    expect(run("1 2 - 4 5 + *")).to eq(-9)
  end

  it "handles floating point numbers" do
    expect(run("1.1 2.2 +")).to eq(3.3)
  end
end
