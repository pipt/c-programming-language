require "spec_helper"

describe "word count" do
  def run(input)
    compile_and_run("chapter-6", "word_count", input).strip
  end

  it "counts the words and outputs them in descending order of frequency" do
    expect(
      run("two one\ntwo\nthree\tthree\tthree")
    ).to eq("3 three\n   2 two\n   1 one")
  end
end
