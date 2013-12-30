require "spec_helper"

describe "swap macro" do
  it "swaps variables of multiple types" do
    expect(compile_and_run("chapter-4", "swap_macro").strip).to eq(
      """a = 1, b = 2
a = 2, b = 1
x = 3.4, y = 5.6
x = 5.6, y = 3.4
s = one, y = two
s = two, y = one"""
    )
  end
end
