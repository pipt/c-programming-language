require_relative "spec_helper"

describe "htoi" do
  def run(input)
    compile_and_run("chapter-2", "htoi", input).strip
  end

  it "works with 0x at the beginning" do
    expect(run("0x2a")).to eq("42")
  end

  it "works with 0X at the beginning" do
    expect(run("0Xbb")).to eq("187")
  end

  it "works without anything at the beginning" do
    expect(run("cc")).to eq("204")
  end

  it "works with capital letters" do
    expect(run("DEADBEEF")).to eq("3735928559")
  end
end
