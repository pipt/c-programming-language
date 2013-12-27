require "spec_helper"

describe "padded_itoa" do
  def run(n, min_width)
    compile_and_run_with_args("chapter-3", "padded_itoa", n, min_width).rstrip
  end

  it "works when number not as wide as given width" do
    expect(run(123, 5)).to eq("  123")
  end

  it "works when number exactly as wide as given width" do
    expect(run(12345, 5)).to eq("12345")
  end

  it "works when number wider than given width" do
    expect(run(1234567, 5)).to eq("1234567")
  end
end
