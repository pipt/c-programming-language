require_relative "spec_helper"

describe "binsearch" do
  def run(search, array)
    compile_and_run_with_stdin_and_args(
      "chapter-3", "binsearch", array.join("\n"), search, array.length
    ).strip
  end

  let(:numbers) { [2, 3, 5, 7, 8] }

  it "finds items at the beginning of the array" do
    expect(run(2, numbers)).to eq("0")
  end

  it "finds items in the middle of the array" do
    expect(run(5, numbers)).to eq("2")
  end

  it "finds items at the end of the array" do
    expect(run(8, numbers)).to eq("4")
  end

  it "returns -1 if the item isn't in the array" do
    expect(run(9, numbers)).to eq("-1")
  end
end
