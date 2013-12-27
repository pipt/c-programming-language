require "spec_helper"

describe "unescape" do
  def run(stdin)
    compile_and_run("chapter-3", "unescape", stdin).strip
  end

  it 'converts \t to tab' do
    expect(run('one\ttwo')).to eq("one\ttwo")
  end

  it 'converts \n to newline' do
    expect(run('one\ntwo')).to eq("one\ntwo")
  end
end
