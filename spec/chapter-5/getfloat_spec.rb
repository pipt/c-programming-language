require "spec_helper"

describe "getfloat" do
  def run(input)
    compile_and_run("chapter-5", "getfloat", input).strip
  end

  def check(float)
    expect(run(float)).to eq("10: %.16f" % float.to_f)
  end

  it "handles positive numbers" do
    check("1.23")
  end

  it "handles negative numbers" do
    check("-1.23")
  end

  it "handles integers" do
    check("1")
  end

  it "handles positive exponents" do
    check("1.23e10")
  end

  it "handles negative exponents" do
    check("1.23e-10")
  end

  it "handles exponents with a capital E" do
    check("1.23E5")
  end

  it "handles exponents with an explicit positive sign" do
    check("1.23e+6")
  end
end
