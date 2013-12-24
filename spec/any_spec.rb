require_relative "spec_helper"

describe "any" do
  def run(*args)
    compile_and_run_with_args("chapter-2", "any", args).strip
  end

  it "returns -1 if no characters are found" do
    expect(run("hello", "x")).to eq("-1")
  end

  it "returns the first position when only one character matches" do
    expect(run("hello", "xl")).to eq("2")
  end

  it "returns the first position when multiple characters match" do
    expect(run("hello", "oe")).to eq("1")
  end
end
