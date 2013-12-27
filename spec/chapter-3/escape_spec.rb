require "spec_helper"

describe "escape" do
  def run(stdin)
    compile_and_run("chapter-3", "escape", stdin).strip
  end

  it 'converts tabs to \t' do
    expect(run("one\ttwo")).to eq('one\ttwo')
  end

  it 'converts newlines to \n' do
    expect(run("one\ntwo")).to eq('one\ntwo')
  end
end
