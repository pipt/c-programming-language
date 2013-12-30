require "spec_helper"

describe "recursive_itoa" do
  def run(n)
    compile_and_run_with_args("chapter-4", "recursive_itoa", n).strip
  end

  it "handles negative numbers" do
    expect(run(-123)).to eq("-123")
  end

  it "handles positive numbers" do
    expect(run(1234)).to eq("1234")
  end

  it "handles zero" do
    expect(run(0)).to eq("0")
  end
end
