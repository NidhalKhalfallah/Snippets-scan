import { ApplicationLoadBalancer, ApplicationLoadBalancerProps, Certificate, Listener } from '@aws-cdk/aws-elasticloadbalancingv2';
import { AutoScalingGroup } from '@aws-cdk/aws-autoscaling';
declare const asg: AutoScalingGroup;
declare const vpc: ec2.Vpc;
const alb = new ApplicationLoadBalancer(this, 'ALB', {
	vpc: vpc,
	internetFacing: true
  });
  //Create a listener for alb
const httpsListener = alb.addListener('HttpsListener', {
  port: 443,
  certificates: [Certificate.fromCertificateArn(this, 'Certificate', 'arn:aws:acm:us-east-1:123456789012:certificate/12345678-1234-1234-1234-123456789012')],
});

httpsListener.addTargets('ASGTarget', {
  port: 80,
  targets: [asg],
});