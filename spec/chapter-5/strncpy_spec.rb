require "spec_helper"

describe "strncpy" do
  def run(*args)
    compile_and_run_with_args("chapter-5", "strncpy", args).strip
  end

  it "copies n characters from one string to another" do
    expect(run("there", 3)).to eq("the")
  end

  it "copies the whole string if shorter than n" do
    expect(run("there", 10)).to eq("there")
  end
end
