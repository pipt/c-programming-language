require "spec_helper"

describe "strend" do
  def run(*args)
    compile_and_run_with_args("chapter-5", "strend", args).strip.to_i
  end

  it "returns 1 if the first string ends with the second" do
    expect(run("there", "here")).to eq(1)
  end

  it "returns 0 if the first string doesn't end with the second" do
    expect(run("there", "one")).to eq(0)
  end

  it "returns 0 if the second string is longer that the first string" do
    expect(run("there", "elsewhere")).to eq(0)
  end
end
