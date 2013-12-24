require_relative "spec_helper"

describe "invert" do
  def run(x, p, n)
    compile_and_run_with_args(
      "chapter-2", "invert", x.to_i(2), p, n
    ).strip
  end

  let(:x) { "01" * 16 }

  it "inverts bits at the end" do
    expect(run(x, 28, 4)).to eq(("01" * 14) + "1010")
  end

  it "inverts bits in the middle" do
    expect(run(x, 16, 8)).to eq(("01" * 8) + ("10" * 4) + ("01" * 4))
  end

  it "inverts bits at the beginning" do
    expect(run(x, 0, 2)).to eq("10" + ("01" * 15))
  end
end
