require "spec_helper"

describe "negative numbers" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip.to_f
  end

  it "accepts negative numbers" do
    expect(run("-12 -15 -")).to eq(3)
  end
end
