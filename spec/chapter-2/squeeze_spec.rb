require "spec_helper"

describe "squeeze" do
  def run(*args)
    compile_and_run_with_args("chapter-2", "squeeze", args).strip
  end

  it "leaves the first string alone when no characters match" do
    expect(run("hello", "abc")).to eq("hello")
  end

  it "removes characters that match" do
    expect(run("hello", "hl")).to eq("eo")
  end
end
