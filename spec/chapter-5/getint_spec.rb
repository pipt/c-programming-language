require "spec_helper"

describe "getint" do
  def run(input)
    compile_and_run("chapter-5", "getint", input).strip
  end

  it "parses numbers" do
    expect(run("1234")).to eq("10: 1234")
  end

  it "returns 0 when just + passed" do
    expect(run("+")).to eq("0: 0")
  end
  it "returns 0 when just - passed" do
    expect(run("-")).to eq("0: 0")
  end
end
