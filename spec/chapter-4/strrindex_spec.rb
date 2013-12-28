require "spec_helper"

describe "strrindex" do
  def run(search, input = string)
    compile_and_run_with_stdin_and_args(
      "chapter-4", "strrindex", input, search
    ).strip.to_i
  end

  let(:string) { "one two three notthree three four five" }

  it "finds things at the beginning" do
    expect(run("one")).to eq(0)
  end

  it "finds things in the middle" do
    expect(run("notthree")).to eq(14)
  end

  it "finds things at the end" do
    expect(run("five")).to eq(34)
  end

  it "returns the rightmost ocurrence when there are multiple" do
    expect(run("three")).to eq(23)
  end

  it "returns -1 if the search string doesn't occur" do
    expect(run("six")).to eq(-1)
  end
end
