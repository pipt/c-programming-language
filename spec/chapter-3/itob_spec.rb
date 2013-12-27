require "spec_helper"

describe "itob" do
  def run(n, base)
    compile_and_run_with_args("chapter-3", "itob", n, base).strip
  end

  def check(n, base)
    expect(run(n, base)).to eq(n.to_s(base))
  end

  it "handles base 2" do
    check(123, 2)
  end

  it "handles base 10" do
    check(123, 10)
  end

  it "handles base 16" do
    check(123, 16)
  end

  it "handles base 36" do
    check(123, 36)
  end
end
