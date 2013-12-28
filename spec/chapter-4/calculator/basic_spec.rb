require "spec_helper"

describe "basic functionality" do
  it "adds" do
    expect(calc("11 22 +")).to eq(33)
  end

  it "subtracts" do
    expect(calc("11 22 -")).to eq(-11)
  end

  it "multiplies" do
    expect(calc("11 22 *")).to eq(242)
  end

  it "divides" do
    expect(calc("11 22 /")).to eq(0.5)
  end

  it "performs multiple operations" do
    expect(calc("1 2 - 4 5 + *")).to eq(-9)
  end

  it "handles floating point numbers" do
    expect(calc("1.1 2.2 +")).to eq(3.3)
  end
end
