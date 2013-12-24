require_relative "spec_helper"

describe "setbits" do
  def run(x, p, n, y)
    compile_and_run_with_args(
      "chapter-2", "setbits", x.to_i(2), p, n, y.to_i(2)
    ).strip
  end

  it "sets bits at the end" do
    x = "10101010"
    y = "01010101"
    expect(run(x, 28, 4, y)).to eq(("0" * 24) + "10100101")
  end

  it "sets bits in the middle" do
    x = "10101010"
    y = "01010101"
    expect(run(x, 8, 8, y)).to eq("00000000" + "01010101" + "00000000" + "10101010")
  end

  it "sets bits at the beginning" do
    x = "10101010"
    y = "01010101"
    expect(run(x, 0, 2, y)).to eq("01000000" + "00000000" + "00000000" + "10101010")
  end
end
