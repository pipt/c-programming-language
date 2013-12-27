require "spec_helper"

describe "bitcount" do
  def run(x)
    compile_and_run_with_args("chapter-2", "bitcount", x.to_i(2)).strip
  end

  it "returns 0 when there are no 1 bits" do
    expect(run("0" * 32)).to eq("0")
  end

  it "returns 7 when there are 7 1 bits" do
    expect(run("1000100010001000100010001")).to eq("7")
  end

  it "returns 32 when all bits are 1 bits" do
    expect(run("1" * 32)).to eq("32")
  end
end
