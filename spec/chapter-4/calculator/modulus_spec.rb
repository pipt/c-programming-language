require "spec_helper"

describe "modulus" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip.to_f
  end

  it "calculates the modulus" do
    expect(run("12 5 %")).to eq(2)
  end
end
