require "AssessmentBase.rb"

module Hellotar
  include AssessmentBase

  def assessmentInitialize(course)
    super("hellotar",course)
    @problems = []
  end

end
