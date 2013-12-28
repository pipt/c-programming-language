require "spec_helper"

describe "math operations" do
  def run(input)
    compile_and_run("chapter-4", "rpn_calc", input).strip.to_f
  end

  it "supports sin" do
    expect(run("#{Math::PI} sin").round(10)).to eq(0)
  end

  it "supports cos" do
    expect(run("#{Math::PI} cos").round(10)).to eq(-1)
  end

  it "supports tan" do
    expect(run("#{Math::PI} tan").round(10)).to eq(0)
  end

  it "supports exp" do
    expect(run("1 exp").round(6)).to eq(Math::E.round(6))
  end

  it "supports pow" do
    expect(run("2 16 pow")).to eq(2 ** 16)
  end
end
