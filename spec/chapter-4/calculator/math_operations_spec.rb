require "spec_helper"

describe "math operations" do
  it "supports sin" do
    expect(calc("#{Math::PI} sin").round(10)).to eq(0)
  end

  it "supports cos" do
    expect(calc("#{Math::PI} cos").round(10)).to eq(-1)
  end

  it "supports tan" do
    expect(calc("#{Math::PI} tan").round(10)).to eq(0)
  end

  it "supports exp" do
    expect(calc("1 exp").round(6)).to eq(Math::E.round(6))
  end

  it "supports pow" do
    expect(calc("2 16 pow")).to eq(2 ** 16)
  end
end
