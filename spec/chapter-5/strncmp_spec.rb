require "spec_helper"

describe "strncmp" do
  def run(*args)
    compile_and_run_with_args("chapter-5", "strncmp", args).strip.to_i
  end

  it "is negative if the first string < second string" do
    expect(run(3, "there", "three")).to be < 0
  end

  it "is positive if the first string > second string" do
    expect(run(3, "three", "there")).to be > 0
  end

  it "returns 0 if the strings match for the first n characters" do
    expect(run(2, "there", "three")).to eq(0)
  end

  it "returns 0 if the strings fully match and are shorter than n" do
    expect(run(10, "three", "three")).to eq(0)
  end
end
